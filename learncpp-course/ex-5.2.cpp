#include <iostream>

int main()
{
    std::cout << "Enter an integer: ";
    int num{0};
    std::cin >> num;
    std::cout << num << " is " << ((num & 1U) == 0 ? "even": "odd" ) << '\n';
}
