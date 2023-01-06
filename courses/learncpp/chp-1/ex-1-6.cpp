#include <iostream>

void doNothing(int&) {}

int main() {
	int x; // uninitialized - the object has not been given a known value 
	x = 5; // assigned a value - the object now has a known value and is no longer uninitialized
	
	doNothing(x);

	std::cout << x << '\n';

	return 0;
}
