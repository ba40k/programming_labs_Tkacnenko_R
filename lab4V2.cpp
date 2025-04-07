#include <iostream>
#include <iomanip>
#include <cmath>
uint64_t Pow(uint64_t val, int p) {
    uint64_t res = 1;
    for (int i = 0; i < p; i++) {
        res *= val;

    }
    return res;
}
//я не решил какой вариант лучше, так как прошлый точнее, а этот ассемблернее
int main() {
    const int n =   5000;
    long double* arr = new long double[n]; // сам ряд
    long double arrConverted[n];// числа ряда приведенные к пи
    int newDigitFound[n];     // метка о том когда открылась новая цифра

    for (int i = 0; i < n; i++) {
        newDigitFound[i] = -1;
    }

    long double target;
    long double twelve = 12;
    long double ten = 10;
    int last_ecx;
    int last_ebx;
    int temp;
    int tempPi;
    arr[0] = 1.0;
    int cur = 1; // последняя неугаданная
   
    long double check;

    __asm {
        
        finit
        fldpi
        fst target
        mov ebx, arr       // Указатель на начало массива
        mov ecx, 1         // Текущий индекс (начинаем с 1)

        loop_start:
        cmp ecx, n         // Проверяем, достигли ли конца массива
            jge loop_end

            // Определение знака (-1)^ecx
            mov eax, ecx
            and eax, 1
            jnz odd

            // Четный индекс: знак 1.0
            fld1
            jmp sign_done

            odd :
        // Нечетный индекс: знак -1.0
        fld1
            fchs              // Меняем знак на -1.0

            sign_done :
        
        mov eax, ecx
            inc eax           // eax = ecx + 1


            push eax
            fild dword ptr[esp]
            add esp, 4        // Очистка стека


            fdivp st(1), st(0)
            // ОЧЕНЬ ВАЖНО! ДЕЛИМ ДВА РАЗА А НЕ ДЕЛИМ НА КВАДРАТ



            push eax
            fild dword ptr[esp]
            add esp, 4        // Очистка стека

            fdivp st(1), st(0)


            mov edx, ecx
            dec edx
            fld qword ptr[ebx + edx * 8]


            faddp st(1), st(0)

            fld st(0)

            fld twelve
            fmulp st(1), st(0)
            fsqrt
            fld st(0)
            
            fstp  qword ptr [arrConverted + ecx*8]
            
            
            mov last_ecx, ecx
            mov ecx, cur
            inc ecx

            fld st(0) // debug
            fstp check

            pow_loop_start:

            fld ten
            fmulp st(1), st(0)
            
            loop pow_loop_start

            fld st(0) // debug
            fstp check
            fistp temp // в темпе 10^cur  * sqrt*(12 * arr[i]), на стеке  arr[i]

            fldpi  // на стеке pi, arr[i]

            
            mov ecx, cur
            inc ecx
            pow_loop_start2 :

            fld ten  // на стеке 10,pi, arr[i]
            fmulp st(1), st(0)  // на стеке 10*pi, arr[i]

            loop pow_loop_start2

            
            fistp tempPi // в темпе 10^cur  *pi, на стеке  arr[i]

            mov ecx, temp

            sub ecx, tempPi

            cmp ecx, 0
            jge positive
            imul ecx, -1
            positive:

            cmp ecx, 1
            mov last_ebx, ebx
            jg not_equal
             mov ecx, last_ecx
             mov ebx, cur
             mov [newDigitFound + ecx * 4], ebx
             inc cur
            not_equal:

            
            mov ebx, last_ebx
            mov ecx, last_ecx
             



            fstp qword ptr[ebx + ecx * 8]

            
            inc ecx
            jmp loop_start

            loop_end :
    }

    for (int i = 0; i < n; i++) {
        if (newDigitFound[i] != -1) {
            std::cout<<"Precision: " << newDigitFound[i] << '\n';
            std::cout <<"Iterations: " << i+1 << '\n';
            std::cout << "Target: " << target << '\n';
            std::cout << "approximation: " << arrConverted[i] << '\n';
            std::cout << "\n==========";
        }
   }
    
   

    delete[] arr;
    return 0;
}
