#include <iostream>

int g_mode{};

void do_something() {
	g_mode = 10;
}

int main() {
	g_mode = 1;
	
	do_something();

	   if (g_mode == 1)
        std::cout << "No threat detected.\n";
    else
        std::cout << "Launching nuclear missiles...\n";

	return 0;
}
