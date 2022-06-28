#include <iostream>

#define PRINT_JOE "joe"

int main()
{
#if defined(PRINT_JOE)
    std::cout << "My name is: " << PRINT_JOE;
#endif

#if !defined(PRINT_BOB)
    std::cout << "My name is: " << PRINT_JOE;
#endif
    return 0;
}
