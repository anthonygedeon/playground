#include <iostream>

#define PRINT_JOE

int main() {
#if defined(PRINT_JOE)
	std::cout << "Joe\n";
#endif

#if !defined(PRINT_BOB)
	std::cout << "BOB\n";
#endif

#if 0
	std::cout << "This won't get printed\n";
#endif
}
