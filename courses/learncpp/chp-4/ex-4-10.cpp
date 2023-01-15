#include <iostream>

bool isPrime(int num)
{
	if (num == 2) {
		return true;
	} else if (num == 3) {
		return true;
	} else if (num == 5) {
		return true;
	} else if (num == 7) {
		return true;
	} 	
	
	return false;
}

int main()
{

	std::cout << "Enter a number between 0 - 9: ";
	
	int num{};
	std::cin >> num;

	if (isPrime(num)) {
		std::cout << "The digit is prime\n";
	} else {
		std::cout << "The digit is not prime\n";
	}

	return 0;
}
