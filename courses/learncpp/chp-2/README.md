# Section 2.1 Quiz Time
1. In a function definition, what are the curly braces and statements in-between called?
	- function bodys

2. What does the following program print? Do not compile this program, just trace the code yourself.

Answer:
starting main
doA
doB
doB
ending main

# Section 2.2 Quiz Time

1a) 16
1b) error
1c) nothing
1d) 5 & 5
1e) error
1f) will compile - never called function

2. Don't Repeat Yourself - it can remove redundant code and keep code consistent

# Section 2.3 Quiz Time
1a) A\nB\n
1b) does not compile
2. when the called function returns early and the caller gets to used the returned value if given a return-type early

# Section 2.4 Quiz Time
1. returns void instead of int
2. the caller doesn't provide the y argument
3. 24
4. 

```c++
	
	int doubleNumber(int num) {
		return num * 2;
	}


```

5.  
```
	int main() {
		
		std::cout << "Enter an integer: ";

		int num{};
		std::cin >> num;

		std::cout << doubleNumber(num) << '\n';
		return 0;
	}

```

# Section 2.6 Quiz Time
1. What does the following program print? 
main: x = 1 y = 2
doIt: x = 1 y = 4
doIt: x = 3 y = 4
main: x = 1 y = 2

# Section 2.7 Quiz Time
1. What is a function prototype?
	- the function prototype, or function declaration, is a forward declaration that has a return-type, identifier, optional parameters with types and identiifers and a semi-colon to end it. 

2. What is a forward declaration?
	- a way to tell the compiler that an identifier exist 

3. How do we declare a forward declaration for functions?
- a function declaration/prototype
```c++
	int foo(int x);
```
4. Write the function declaration for this function (use the preferred form with names):
```c++
	int doMath(int first, int second, int third, int fourth);
```

5. For each of the following programs, state whether they fail to compile, fail to link, fail both, or compile and link successfully. If you are not sure, try compiling them!

a) fail to compile
b) fail to compile
c) compiles but fails to link
d) successfully compile and link

# Section Quiz Time 2.7
```c++
// get_integer.cpp

#include <iostream> 

int getInteger()
{
	std::cout << "Enter an integer: ";
	int x{};
	std::cin >> x;
	return x;
}
```

```c++
// main.cpp
#include <iostream> 

int getInteger(); 

int main()
{
	int x{ getInteger() };
	int y{ getInteger() };

	std::cout << x << " + " << y << " is " << x + y << '\n';
	return 0;
}
```

# Section 2.12 Quiz TIme
1. Add header guards to this header file:
```c++
#if !defined(ADD_H)
#define ADD_H
	int add(int x, int y);
#endif
```
