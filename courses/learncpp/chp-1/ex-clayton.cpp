#include <iostream> //only used cout and cin
#include <numbers>
#include <cmath>

inline int get_area_of_right_triangle(int base, int height) {
	return base * height / 2;
}

inline int get_area_of_circle(int radius) {
	return std::numbers::pi * std::pow(radius, 2);
}

inline int get_area_of_square(int length) {
	return length * 2;
}

int main() {
	std::cout << 
		"1 - Find Area of Square\n" << 
		"2 - Find Area of Circle\n" <<
		"3 - Find Area of Right Triangle\n" <<
		"4 - Exit Program\n" <<
        "Enter the number of your preferred action : ";

	int choice{ };
	std::cin >> choice;

	switch (choice) {
		case 1: {
			std::cout << "Enter the length : ";

			int length{ }; 
			std::cin >> length;

			std::cout << "The area of your square is : " << get_area_of_square(length) << '\n'; 
			break;
		}
		case 2: {
			std::cout << "Enter the radius : ";

			int radius{ }; 
			std::cin >> radius;

			std::cout << "The area of your circle is : " << get_area_of_circle(radius) << '\n'; 
			break;
		}
		case 3: {
			std::cout << "Enter the base : ";
			int base{ }; 
			std::cin >> base;

			std::cout << "Enter the height : ";
			int height { }; 
			std::cin >> height;

			std::cout << "The area of your right triangle is : " << get_area_of_right_triangle(base, height) << '\n';
			break;
		}
		case 4: {
        	std::cout << "You have quit the program.\n";
			break;
		}
	}

    std::cout << "Thank you for using the program\n";

	return 0;
}
