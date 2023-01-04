#include <iostream>
#include <limits>

// COME BACK
int main() {
	std::cout << "Hello World!" << std::endl;
	
	// wait for user input
	std::cin.clear(); // reset any error flags
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore any charaters in the input buffer until we find a \n
	std::cin.get(); // waits for user to type in something and until user presses ENTER
		
	// doesn't work on my machine
	// std::system("pause") 
	
	// -D macro flag
	#ifdef NDEBUG
		std::cout << "-D macro flag test" << std::endl;
	#endif

	return 0;
}
