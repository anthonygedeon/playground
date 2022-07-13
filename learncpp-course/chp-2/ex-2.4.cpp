#include <iostream>

int doubleNumber(int x) {
       return x * 2; 
}

int getUserInput() {
        int num{};
        std::cout << "Enter Integer: ";
        std::cin >> num;
        return num;
}

int main() {
    int user_value = getUserInput();
    std::cout << doubleNumber(user_value) << "\n";
    return 0;
}
