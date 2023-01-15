#include <iostream>

// no point in adding const parameters when it's passed by value
void printInt(const int x)
{
	// pass by value is just a copy so x is created
	std::cout << x << '\n';
} // and then destroyed here

const int getValue()
{
	return 5;
}

int main()
{
#if defined(EX_1)
	const double gravity { 9.8 };
	int const sidesInSquare { 4 };
#endif

#if defined(EX_2)
	const double gravity;
#endif

#if defined(EX_3)
	std::cout << "Enter your age: ";
    int age{};
    std::cin >> age;

	const int constAge { age };
	age = 5;
	constAge = 10;
#endif

#if defined(EX_4)
	printInt(5);
	printInt(6);

#endif

#if defined(EX_5)
	std::cout << getValue() << '\n';
#endif
}
