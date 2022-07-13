#include <iostream>

#include <cstdint>

struct RGBA {
	std::uint8_t r;
	std::uint8_t g;
	std::uint8_t b;
	std::uint8_t a;
};

int main() {
	RGBA color { 0xAA, 0xBB, 0xCC, 0xDD };

	std::uint32_t pixel{};		
	pixel |= (color.r << 24);
	pixel |= (color.g << 16);
	pixel |= (color.b << 8);
	pixel |= color.a;
	

	std::cout << std::hex;
	std::cout << pixel << '\n';

	return 0;
}
