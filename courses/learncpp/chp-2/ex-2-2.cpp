#include <iostream>

int getValueFromUser() {
	std::cout << "Enter an integer: ";
	int input{};
	std::cin >> input;
	return input;
}

#ifdef EXAMPLE_1
int getValueFromUserUB() {
	std::cout << "Enter an integer: ";
	int input {};
	std::cin >> input;
}

int main() {
	int num { getValueFromUser() };
	int numUB { getValueFromUserUB() };	

	std::cout << numUB << " doubled is: " << numUB * 2 << '\n';
	std::cout << num << " doubled is: " << num * 2 << '\n';

	return 0;
}
#endif

#ifdef EXAMPLE_2
int main() {
	
	int x{ getValueFromUser() };
	int y{ getValueFromUser() };
	
	std::cout << x << " + " << y << " = " << x + y << '\n';

	return 0;
}
#endif
