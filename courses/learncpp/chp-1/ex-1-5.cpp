#include <iostream>

int main() {
	std::cout << "Enter a number: ";
	int a{};
	std::cin >> a;
	std::cout << "You entered: " << a << '\n';

	std::cout << "Enter two numbers seperated by space: ";

	int x{};
	int y{};
	std::cin >> x >> y;	
	
	std::cout << "You entered " << x << " and " << y << '\n';

	return 0;
}
