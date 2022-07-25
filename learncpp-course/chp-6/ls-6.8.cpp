#include <iostream>

int initx();
int inity();

int g_x{ initx() };
int g_y{ inity() };

int initx() {
	return g_y;
}

int inity() {
	return 5;
}

namespace constants {
	constexpr double gravity { 9.8 };
}

namespace constants_2 {
	extern const double gravity { 9.8 };
}

double get_gravity() {
	return constants::gravity;
}

double instant_velocity(int time, double gravity) {
	return gravity * time;
}

int main() {
	std::cout << constants::gravity << '\n';
	std::cout << constants_2::gravity << '\n';
	std::cout << get_gravity() << '\n';
	std::cout << instant_velocity(5, constants::gravity) << '\n';
	
	std::cout << g_x << ' ' << g_y << '\n';
}
