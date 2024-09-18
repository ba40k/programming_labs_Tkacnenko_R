// taylor task 12
// 1 + x^2/2! + x^4/4...
#include <iostream>
#include <cmath>
#include <iomanip>

int main()
{
    int x, k;
    std::cin >> x >> k; // ввод
    long double res = 0; // сумма
    long double factorial = 1; // значение факторила, начиная с 0
    long double epsilon = pow(10, -k);
    int power = 1;
    long double last_numerator = x;
    for (int i = 1; ; i++)
    {
        power = 1 << (i - 1); // определение степени x у текущего члена, а также числа, факториал которого нам нужен
        long double cur_numerator = x;
        if (i > 1)
        {
            cur_numerator = last_numerator * last_numerator; // возведение предыдущего числителя  в квадрат
            last_numerator = cur_numerator;
        }
        for (int j = power / 2 + 1; j <= power; j++) /* так как факториал вынесен вне цикла, его значение
                                                для предыдущего случая уже сохранено, то есть если сейчас нам надо вычислить
                                                8!, то мы в прошлый раз вычислили 4!, а значит теперь нам надо идти с 5*/
        {
            factorial *= j;
        }
        long double cur_number = cur_numerator / factorial; // текущий член ряда Тейлора
        res += cur_number;



        std::cout << std::fixed << std::setprecision(k) << "x= " << i << "; taylor(x)= " << cur_number << " | epsilon=" << epsilon << '\n';

        if (cur_number < epsilon) // проверка того, что текущий член меньше epsilon
        {
            break;
        }
    }
    std::cout << std::fixed << std::setprecision(k) << "sum is " << '\n' << res;

}
