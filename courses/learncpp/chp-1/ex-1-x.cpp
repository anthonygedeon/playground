#include <iostream>

int main() {
	std::cout << "Enter an integer: ";
	
	int num_1 { };
	std::cin >> num_1;

	std::cout << "Enter another integer: ";

	int num_2 { };
	std::cin >> num_2;

	std::cout << num_1 << " + " << num_2 << " is " << num_1 + num_2 << ".\n";
	std::cout << num_1 << " - " << num_2 << " is " << num_1 - num_2 << ".\n";

	return 0;
}
