#include <iostream>
#include <cmath>

#if defined(EX_1)
double user_input()
{
	std::cout << "Enter a double value: ";
	double num{};
	std::cin >> num;

	return num;
}

char get_operator()
{
	std::cout << "Enter one of the following: +, -, *, or /: ";
	char op{};
	std::cin >> op;

	return op;
}

double calculate(char op, double a, double b)
{
	double result{};
	switch (op)
	{
		case '+':
			result = a + b;
			break;
		case '-':
			result = a - b;
			break;
		case '*':
			result = a * b;
			break;
		case '/':
			result = a / b;
			break;
		default:
			result = 0;
			break; } return result;
}

int main() 
{
	double num1 { user_input() };
	double num2 { user_input() };
		
	char op { get_operator() };
	
	double result { calculate(op, num1, num2) };

	std::cout << num1 
		<< " " << op 
		<< " " << num2 << " is " 
		<< result << '\n';

	return 0;
}
#endif

#if defined(EX_2)

double compute_distance_fallen(float g, int sec)
{
	return (g * (std::pow(sec, 2))) / 2;
}

int main()
{
	constexpr float gravity { 9.8 };
	
	std::cout << "Enter the height of the tower in meters: ";
	float meters{};
	std::cin >> meters;

	for (auto sec { 0 }; sec < 6; ++sec)
	{
		if (auto fallen { compute_distance_fallen(gravity, sec) }; (meters-fallen) > 0)
		{
			std::cout << "At " << sec 
				<< " seconds, " 
				<< "the ball is at height: " 
				<< (meters-fallen)
				<< '\n';
		} else {
			std::cout << "At " << sec << " seconds, " << "the ball is on the ground\n";
			break;
		}
	}
	return 0;	
}
#endif
