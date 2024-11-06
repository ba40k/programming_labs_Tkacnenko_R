#include <iostream>
#include "frac.h"

int main()
{
    // ВАЖНО ! Если вам покажется, что какие-то операции дают неправильный ответ
    // ВАЖНО ! то посмотрите на метод makePropert
    properFrac f(-5, 4);
    properFrac f2(7, 8);
    properFrac f4(0, 5);
    properFrac f3(1, 0);

    (f2+f2 + f4 + f3).show();
    std::cout << '\n';
    (f * f2).show(); // например здесь все правильно
    std::cout << '\n';

    properFrac a(10, 5);
    properFrac b(11, 11);
    properFrac d(-17, 7);
    properFrac e(20, 11);
    (a / b).show();
    std::cout << '\n';
    (d - e).show();
}
