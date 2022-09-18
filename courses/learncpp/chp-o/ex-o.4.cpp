#include <iostream>

#include <cstdint>
#include <string>
#include <algorithm>

int dec_to_bin(std::uint8_t num);

int main() {
	std::cout << "Enter a number between 0 - 255: ";

	int bin{ 0 };
	if (bin < 0 || bin > 255) return -1;
	std::cin >> bin;
	
	int b_1{ dec_to_bin(bin) };
	bin /= 2;
	int b_2{ dec_to_bin(bin) };
	bin /= 2;
	int b_3{ dec_to_bin(bin) };
	bin /= 2;
	int b_4{ dec_to_bin(bin) };
	bin /= 2;
	int b_5{ dec_to_bin(bin) };
	bin /= 2;
	int b_6{ dec_to_bin(bin) };
	bin /= 2;
	int b_7{ dec_to_bin(bin) };
	bin /= 2;
	int b_8{ dec_to_bin(bin) };

	std::cout << b_8;	
	std::cout << b_7;	
	std::cout << b_6;	
	std::cout << b_5 << ' ';	
	std::cout << b_4;	
	std::cout << b_3;	
	std::cout << b_2;	
	std::cout << b_1;	
	std::cout << '\n';
	return 0;
}

int dec_to_bin(std::uint8_t num) {
	return num % 2 ? 1 : 0;
}
