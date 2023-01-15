#include <iostream>

int getASCIICode0(int ch) { return ch; }
int getASCIICode1(char ch) { return ch; }

int main()
{
	std::cout << "Enter a single character: ";

	std::uint8_t ch{};
	std::cin >> ch;

	// Solution 0:
	std::cout << "You entered " 
		<< "\'" << ch << "\', " << "which has ASCII code " << static_cast<int>(ch) << ".\n";

	// Solution 1:
	std::cout << "You entered " 
		<< "\'" << ch << "\', " << "which has ASCII code " << getASCIICode0(ch) << ".\n";
	
	// Solution 2:
	std::cout << "You entered " 
		<< "\'" << ch << "\', " << "which has ASCII code " << (ch+0) << ".\n";

	// Solution 3:
	std::cout << "You entered " 
		<< "\'" << ch << "\', " << "which has ASCII code " << getASCIICode1(ch) << ".\n";

	// Solution 4:
	int ascii{ ch };
	std::cout << "You entered " 
		<< "\'" << ch << "\', " << "which has ASCII code " << ascii << ".\n";

	return 0;
}
