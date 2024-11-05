#include <iostream>
#include "frac.h"

int main()
{
    // ВАЖНО ! Если вам покажется, что какие-то операции дают неправильный ответ
    // ВАЖНО ! то посмотрите на метод make_correct
    frac f(-5, 4);
    frac f2(7, 8);
    frac f4(0, 5);
    frac f3(1, 0);

    (f2+f2 + f4 + f3).show();
    std::cout << '\n';
    (f * f2).show(); // например здесь все правильно
}
