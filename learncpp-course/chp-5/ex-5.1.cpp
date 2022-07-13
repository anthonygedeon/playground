#include <iostream>

int getValue()
{
    std::cout << "Enter an integer: ";

    int x{};
    std::cin >> x;
    return x;
}

void printEquation(int result)
{
    // g++:     prints 5
    // clang++: prints 7
    std::cout << result << '\n';
}

void calculateEquation(int x, int y, int z)
{
    // g++:     x = 3, y = 2, z = 1
    //          3 + (2 * 1)

    // clang++: x = 1, y = 2, z = 3
    //          1 + (2 * 3)
    printEquation(x + (y * z));
}

int main()
{
    calculateEquation(getValue(), getValue(), getValue());
    return 0;
}
