#include <iostream>
#include <algorithm>
#include <string>

int main()
{
	//std::cout << "Pick 1 or 2: ";
	//int choice{};
	//std::cin >> choice;

	//std::cout << "Now enter your name: ";
	//std::string name{};
	//std::getline(std::cin >> std::ws, name);

	//std::cout << "Hello, " << name << ", you picked " << choice << '\n';
	
	//std::string name { "Alex" };
	//std::cout << name << " has " << name.length() << " characters\n";

#if defined (EX)
	std::cout << "Enter your full name: ";
	std::string name{};
	std::getline(std::cin >> std::ws, name);

	std::cout << "Enter you age: ";
	int age{};
	std::cin >> age;

	std::cout << "Your age + length of name: " << ( static_cast<int>(name.length()) + age ) << '\n';
#endif

	return 0;
}
