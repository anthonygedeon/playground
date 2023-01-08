#include <iostream>

void doPrint() {
	std::cout << "In doPrint()\n";
}

void doB() {
	std::cout << "In doB()\n";
}

void doA() {
	std::cout << "starting doA()\n";
	doB();
	std::cout << "ending doA()\n";
}

int main() {
	std::cout << "starting main()\n";
	doA();
	std::cout << "ending main()\n";
	return 0;
}
