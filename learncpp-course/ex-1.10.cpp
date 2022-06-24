#include <iostream>

int main() {
	std::cout << 2 + 3 << '\n'; // 5

	int x{ 6 }; 
	int y{ x - 2 };
	std::cout << y << '\n'; // 4 
                                
	int z{ };
	z = x;
	std::cout << z - x << '\n'; // 0

	return 0;
}
