# Section 1.1 - Quiz Time 

1. What is a statement?
	- anagolous to sentences, statements is code that performs an action

2. What is a function?
	- a function is a group of statements that performs something

3. What is the name of the function that all programs must have?
	- `main()`

4. When a program is run, where does execution start?
	- the first line of code in the main function

5. What symbol are statements in C++ often ended with?
	- semicolon `;`

6. What is a syntax error?
	- a compiler-error when you use invalid c++ syntax or violations of the language
	- NOTE: syntax errors occur during compilation i.e it's a compile-time error not runtime

7. What is the C++ Standard Library?
	- precompiled header files for use in your programs to assist with mundane code such as flipping a bit or printing out characters using `iostream`

# Section 1.3 - Quiz Time

1. What is data?
	- data is information that can be stored, processed, and moved 
	- we use statements to manipulate this data

2. What is a value?
	- taken space in memory that contains data

3. What is a variable?
	- an object that has been assigned a region of storage and has a name

4. What is an identifier?
	- the name of the object

5. What is a type?
	- a type tells the compiler how to understand a value

6. What is an integer?
	- a number without the fraction part i.e -2, 0, 2 100

# Section 1.4 Quiz Time

1. What is the difference between initialization and assignment?
	- initialization is when a variable has a initializer as part of the definition while assignment is a two-part statement, the first part being the declaraction of the variable `int x;` and the second part being the assignment to x i.e `x = 5;`

2. What form of initialization should you be using?
	- Direct Brace initialization

# Section 1.5 Quiz Time
1. Consider the following program that we used above: 
```cpp
#include <iostream>  // for std::cout and std::cin

int main()
{
    std::cout << "Enter a number: "; // ask user for a number
    int x{}; // define variable x to hold user input
    std::cin >> x; // get number from keyboard and store it in variable x
    std::cout << "You entered " << x << '\n';
    return 0;
}
```
The program expects you to enter an integer value, as the variable x that the user input will be put into is an integer variable.

Run this program multiple times and describe what happens when you enter the following types of input instead:

a. A letter, such as h
	- it will return 0 because ...

b. A number with a fractional component. Try numbers with fractional components less than 0.5 and greater than 0.5 (e.g. 3.2 and 3.7).
	- chops off the fractional part since we are using value initialization 

c. A small negative integer, such as -3
	- it will output -3 since it's an acceptable type for x

d. A word, such as Hello
	- 0 once again

e. A really big number (at least 3 billion)
	- it will print out the MAX value of the type int

f. A small number followed by some letters, such as 123abc
	- 123
