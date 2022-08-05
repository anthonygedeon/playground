#include <iostream>
#include <string>

double get_user_value() {
        std::cout << "Enter a double value: ";
        double num{};
        std::cin >> num;

        return num;
}

char get_math_operator() {
        std::cout << "Enter one of the following: +, -, *, or /: ";
        char math_operator{};
        std::cin >> math_operator;
        return math_operator;
}

void print_result(double num_1, char math_operator, double num_2) {
    double answer{};
    switch(math_operator) {
        case '+':
            answer = num_1 + num_2;
            break;  
        case '-':
            answer = num_1 - num_2;
            break;  
        case '*':
            answer = num_1 * num_2;
            break;  
        case '/':
            if (num_2 == 0) {
                std::cout << "cannot divide by 0" << '\n';
                return;
            }
            answer = num_1 / num_2;
            break;  
        default:
            std::cout << "invalid math operator" << '\n';
            return;
            break;
    }

    std::cout << num_1 << " " << math_operator << " " << num_2 << " is " << answer << '\n';
}

int main() {
    // Quiz 1:
    // a: 
    // b: 

    // Quiz 2
    // a: int 
    // b: bool 
    // c: double
    // d: int
    // e: float
    // f: std::int32_t 
    // g: char
    // h: std::int16_t

    // Quiz 3:
    //double num_1 = get_user_value();
    //double num_2 = get_user_value();

    //char math_operator = get_math_operator();

    //print_result(num_1, math_operator, num_2);

    // Quiz 5:
    std::cout << "How old are you?\n";

    int age{};
    std::cin >> age;

    constexpr std::int16_t minimum_age_to_drive{ 16 };
    std::cout << "Allowed to drive a car in Texas [" 
              << (age >= minimum_age_to_drive ? 'x' : ' ') << "]\n";
    
    return 0;
}
