#include <iostream>

int main() { // 1
	std::cout << "Enter an integer: ";
	int value{};
	std::cin >> value;

	if (value >= 0) { // 2
		std::cout << value << " is a positive integer (or zero)\n";
	} else { //3 
		
	}
	
	// clang issues a warning when using a if statement without a block;
	// you can use short circutting to repurpose this feature but I wouldn't advise this
	if (value < 0 || (value = 10));

	std::cout << value << '\n';

	if (1) { // 1
		if (1) { // 2
			if (1) { //3 
				if (1) { // 4
					if (1) { // 5
						if (1) { // 6
							if (1) { // 7
								if (1) { // 8
									if (1) { // 9
										if (1) { // 10
											std::cout << "hello" << '\n';
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}

	return 0;
}


