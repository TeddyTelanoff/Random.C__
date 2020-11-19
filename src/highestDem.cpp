#include <iostream>

int numerator = 4; // You can change this!
int denominator = 20; // You can change this!
// Gives Fraction 4/20 or 1/5.
// Common Denominator should be 4.

int main()
{
	while (denominator != 0)
		if (numerator > denominator)
			numerator -= denominator;
		else
			denominator -= numerator;
	std::cout << "The Common Denominator is " << numerator << "!" << std::endl;

	std::cin.get();
}