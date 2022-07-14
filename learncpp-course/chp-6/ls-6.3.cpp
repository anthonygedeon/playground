#include <iostream>
#include <utility>

namespace value {
	int get_smaller_value() {
		std::cout << "Enter an integer: ";
		int value_a {}; // enters scope 
		std::cin >> value_a;
		return value_a;
	}

	int get_large_value() {
		std::cout << "Enter a larger integer: ";
		int value_b {};
		std::cin >> value_b;
		return value_b;
	}
}

int main() {
	namespace getter = value;

	int small_value {getter::get_smaller_value()};
	int large_value {getter::get_large_value()};
	
	if (small_value > large_value) { // nested block
		std::cout << "Swapping the values\n";
		std::swap(small_value, large_value);
	} // temp is out of scoped and destroyed 

	std::cout << "The smaller value is: " << small_value << '\n';
	std::cout << "The larger value is: " << large_value << '\n';

	return 0;
} // value_a & value_b are destroyed here and are no longer accessible 

// [Q2]
// Variable scope   - where you can use this variable
// storage duration - it configures the lifetime of the variable [wrong] 
// 					- Duration defines the rules that govern when a var is created and destroyed [correct]
// lifetime			- the time of birth and death of an object
//
// local variables have block scope and automatic storage 
// automatic duration for a variable means that it will be created at the point of definition and destroyed within that block that it was defined in 
//
