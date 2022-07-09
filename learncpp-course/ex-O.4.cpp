#include <iostream>

#include <cstdint>
#include <string>
#include <algorithm>

std::string dec_to_bin(std::uint8_t num);

int main() {
	std::cout << "Enter a number between 0 - 255: ";

	int bin{ 0 };
	if (bin < 0 || bin > 255) return -1;
	std::cin >> bin;
	
	std::string result{ dec_to_bin(bin) };

	std::cout << result << '\n';

	return 0;
}

std::string dec_to_bin(std::uint8_t num) {
	// if (num % 2 != 0) then
	// remainder = divide num / 2
	// add bit to string

	// return string.reverse()

	std::string binary{};

	while (num > 0) {
		if (num % 2 != 0) {
			binary.push_back('1');
		} else {
			binary.push_back('0');
		}
		num /= 2;
	}


	for (int i = binary.length(); i < 8; i++) {
		binary += "0";
	}

	std::reverse(binary.rbegin(), binary.rend());

	return binary;
}
