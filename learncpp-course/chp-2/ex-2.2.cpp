#include <iostream>

int returnFive()
{
    return 5;
}

int returnSomething() {
        std::cout << "hello\n";
}

int main()
{
    std::cout << returnFive() << '\n';
    std::cout << returnSomething() << "\n";
    return 0;
}
