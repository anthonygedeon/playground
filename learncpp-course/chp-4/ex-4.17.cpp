#include <iostream>
#include <string>
#include <string_view>

int main() {
    std::cout << "Enter your full name: ";
    std::string full_name{};
    std::getline(std::cin >> std::ws, full_name);
    

    std::cout << "Enter your age: ";
    int age{};
    std::cin >> age;

    std::cout << "Your age + length of name: " 
              << static_cast<int>(full_name.length()) + age << '\n';

    return 0;

}

