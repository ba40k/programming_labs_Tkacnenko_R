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
int main() {
    const int n = 1000000;
    long double* arr = new long double[n];

    long double target;
    arr[0] = 1.0;


    __asm {
        fldpi
        fst target
        finit 
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
        // Вычисление (ecx + 1)^2
        mov eax, ecx
            inc eax           // eax = ecx + 1
           // imul eax, eax     // eax = (ecx + 1)^2

            
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
            fstp qword ptr[ebx + ecx * 8]

           
            inc ecx
            jmp loop_start

            loop_end :
    }

   
    
    int cur = 1;
   
    for (int i = 0; i < 1000000; ++i) {
        arr[i] = sqrtl(12 *(arr[i]));
        if (cur > 16) {
            break;
       }

        if (static_cast<uint64_t>(target * Pow(10,cur)) == static_cast<uint64_t>(arr[i] * Pow(10, cur))) {
            if (cur == 11) {
                std::cout << static_cast<uint64_t>(target * Pow(10, cur)) << '|' << static_cast<uint64_t>(arr[i] * Pow(10, cur));
            }
            std::cout << "precision is " << cur << '\n';
            std::cout<< "target is :" <<std::fixed<<std::setprecision(100)<< target << '\n';
            std::cout<< "iterations is: " << i + 1 << '\n';
            std::cout << "current is " << std::fixed << std::setprecision(100)<< arr[i] << '\n';
            std::cout << "=========\n";
            cur++;
        }
       
    }

    delete[] arr;
    return 0;
}
