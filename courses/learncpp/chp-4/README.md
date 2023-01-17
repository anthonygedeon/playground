# Section 4.10 Quiz Time

2. 
```cpp
#include <iostream>

bool isAllowedToTakeFunRide()
{
  std::cout << "How tall are you? (cm)\n";

  double height{};
  std::cin >> height;

  return height > 140.0;
}

int main()
{
  if (isAllowedToTakeFunRide())
    std::cout << "Have fun!\n";
  else
    std::cout << "Sorry, you're too short.\n";

  return 0;
}
```

# Section 4.x Quiz Time
1. Why are symbolic constants usually a better choice than literal constants? Why are const/constexpr symbolic constants usually a better choice than #defined symbolic constants?
	- Prevent magic numbers, remember we code for the person than the computer	

	- #define ignore scope
	- when includes, they can accidentally substitute a lowercase variable name that is the same name as the #define
	- you can store a const in a variable unlike #define
	- #define symbolic constants do not show up when debugging which accumulates over head


2. 
a) The age of the user (in years) (assume the size of the type isn’t important)
 	- int 

 b) Whether the user wants the application to check for updates
 	- bool

 c) pi (3.14159265)
 	- constexpr double

 d) The number of pages in a textbook (assume size is not important)
 	- std:int16_t

 e) The length of a couch in feet, to 2 decimal places (assume size is important)
 	- float

 f) How many times you’ve blinked since you were born (note: answer is in the millions)
 	- std::int32_t

 g) A user selecting an option from a menu by letter
 	- char

 h) The year someone was born (assuming size is important)
 	- const int16_t

Question #5
1. Find 3 issues (affecting 4 lines) in the following code.
	- Not converting age to int using static_cast<T>()
	- using a magic number for 16, should be `constexpr minimum_age_to_drive`
	- "x" should be a 'x'
