#include <iostream>

int g_y;
const int g_x{};
constexpr int g_test{};

int main() {
	std::cout << g_y << '\n';
	std::cout << g_x << '\n';
	std::cout << g_test << '\n';
	return 0;
}
