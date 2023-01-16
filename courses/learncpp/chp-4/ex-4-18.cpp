#include <iostream>
#include <string_view>

void printString(std::string_view str)
{
	std::cout << str << '\n';
}

int main()
{
	std::string s { "Hello, world!" };
	std::string_view ssv { s };
	constexpr std::string_view sv { "hello" };

    return 0;
}
