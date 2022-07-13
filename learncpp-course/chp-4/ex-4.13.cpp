#include <iostream>

const int printInt(const int x) {
        std::cout << x;
        return 10;
}

int main() {
    int a = printInt(5);
    int b = printInt(6);
        
    a = 3;

    std::cout << a;


    return 0;
}
