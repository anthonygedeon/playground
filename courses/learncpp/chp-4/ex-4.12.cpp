#include <iostream>

int main() {
    
    std::cout << "Enter a single character: ";

    char user_response{};
    std::cin >> user_response; 
    
    std::cout << "You entered '" << user_response << "', " << "which has ASCII code " << user_response + 0 << '\n';

    return 0;
}
