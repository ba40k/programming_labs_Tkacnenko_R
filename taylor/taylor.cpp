// taylor task 12
// 1 + x^2/2! + x^4/4...
#include <iostream>
#include <cmath>

int main()
{
    int x,k;
    std::cin>>x>>k; // ввод
    long double res = 0; // сумма
    long double factorial =1; // значение факторила, начиная с 0
    long double epsilon = pow(10,-k); 
    for (int i =1; ;i++)
    {
        int power = pow(2,i-1); // определение степени x у текущего члена
        long double cur_numerator = pow(x,power); // вычисление числителя текущего члена, а также числа, факториал которого нам нужен
        for (int j = power/2+1;j<=power;j++) /* так как факториал вынесен вне цикла, его значение 
                                                для предыдущего случая уже сохранено, то есть если сейчас нам надо вычислить
                                                8!, то мы в прошлый раз вычислили 4!, а значит теперь нам надо идти с 5*/                                          
        {
            factorial*=j;
        }
        long double cur_number = cur_numerator/factorial; // текущий член ряда Тейлора
        res+=cur_number; 
        
       
        
        std::cout<<"x= "<<i<<"; taylor(x)= "<<cur_number<<" | epsilon="<<epsilon<<'\n';

        if (cur_number< epsilon) // проверка того, что текущий член меньше epsilon
        {
            break;
        }
    }
    std::cout<<"sum is "<<'\n'<<res;

}