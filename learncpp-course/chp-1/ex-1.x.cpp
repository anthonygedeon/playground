#include <iostream>

int main() {
    int num_1{};
    std::cout << "Enter an interger: ";
    std::cin >> num_1;

    int num_2{};
    std::cout << "Enter another interger: ";
    std::cin >> num_2;
        
    std::cout << num_1 << " + " << num_2 << " is " << num_1 + num_2 << ".\n";
    std::cout << num_1 << " - " << num_2 << " is " << num_1 - num_2 << ".\n";

    return 0;
}
