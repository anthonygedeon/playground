#include <iostream>

int add(int x, int y) {
	int z { x + y };

	return z;
}

void doSomething() {
	std::cout << "Hello!\n";
}

int main() {
	int x { 0 }; // x is born :)

	doSomething()

	return 0;
} // x is dead :(

