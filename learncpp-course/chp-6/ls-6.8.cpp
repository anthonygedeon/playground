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

int main() {
	std::cout << g_x << ' ' << g_y << '\n';
}
