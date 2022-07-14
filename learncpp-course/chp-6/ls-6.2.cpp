#include "ls-6.2.circle.h" 
#include "ls-6.2.growth.h" 

#include <iostream>

int add(int x, int y) {			
	return x + y;
}

namespace foo {

	int add(int x, int y) {
		return ::add(x, y);
	}
}

namespace foo::goo {

	int add(int x, int y) {
		return x + y;
	}

}

int main()
{
	namespace mathstuff = foo::goo;

	std::cout << basic_math::pi << '\n';
	std::cout << basic_math::e << '\n';
	std::cout << mathstuff::add(5, 5) << '\n';
	std::cout << foo::add(5, 5) << '\n';

	return 0;
}
