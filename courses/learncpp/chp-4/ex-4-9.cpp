#include <iostream>

int main()
{
	bool b{};
	std::cout << "Enter a boolean value: ";
	std::cin >> std::boolalpha >> b;
	std::cout << "You Entered: " << b<< '\n';
	return 0;
}
