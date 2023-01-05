#include <iostream>
#include <string>

int main() {
	[[maybe_unused]] int a; // default initializer
	
	// Copy initialization
	// 5 is the initializer
	[[maybe_unused]] int b = 5; 
	
	// Direct initialization
	// 6 is the initializer
	[[maybe_unused]] int c( 6 ); 
	
	// Brace initialization
	// 7 is the initializer
	[[maybe_unused]] int d { 7 }; 

	[[maybe_unused]] int width { 5 }; // prefered: direct brace initialization
	[[maybe_unused]] int height = { 6 }; // copy brace initialization
	[[maybe_unused]] int depth = {}; // value initialization
	
	int test0 { 7 };
	int test1 = 7.5;

	std::cout << test0 << ' ' << test1 << '\n';
	
	// zero initialization & value initialization
	int zero {};
	std::cout << zero << '\n';

	// int a, b = 5; -> error
	// int a = 5, b = 5; -> correct
	// int e { 9 }, f { 10 }; -> correct
	
	// this will send a warning:
	[[maybe_unused]] int x { 5 };

	// x is not used
	
	std::string name;
	name = { "John" };

	std::cout << "My name is: " << name << '\n';

	return 0;	
}
