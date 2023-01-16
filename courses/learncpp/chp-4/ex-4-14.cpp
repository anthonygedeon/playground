#include <iostream>

constexpr int five()
{
	return 5;
}

int main()
{
	constexpr double gravity { 9.8 };
	constexpr int sum { 4 + 5 };
	constexpr int something { sum };

	std::cout << "Enter your age: ";
	int age{};
	std::cin >> age;

	const int myAge { age };
	
	constexpr int f { five() };

	return 0;
}
