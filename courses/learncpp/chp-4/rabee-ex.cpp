#include <iostream>

bool isEqual(int x, int y) {
	return (x == y);
}

int getInput() {
	std::cout << "Enter a number: ";
	int x {};
	std::cin >> x;

	return x;
 }

// didn't work previously because the parameter accepted int types
void answerInput(bool value) {
	std::cout << "The answer is: " << value << '\n';
}

int main()
{
   int x { getInput() };
   int y { getInput() };

	std::cout << std::boolalpha;
   	answerInput(isEqual(x, y));

   return 0;
}
