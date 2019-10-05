#include <iostream>
#include "rectangle.h"

using namespace lr2;

int main() {
    Point leftDown1, rightUp1, leftDown2, rightUp2;

    std::cout << "First point's coordinates of the first rectangle (x y): ";
    std::cin >> leftDown1;

    std::cout << "Second point's coordinates of the first rectangle (x y): ";
    std::cin >> rightUp1;

    std::cout << "First point's coordinates of the second rectangle (x y): ";
    std::cin >> leftDown2;

    std::cout << "Second point's coordinates of the second rectangle (x y): ";
    std::cin >> rightUp2;

    std::cout << Rectangle(leftDown1, rightUp1) - Rectangle(leftDown2, rightUp2);
    return 0;
}
