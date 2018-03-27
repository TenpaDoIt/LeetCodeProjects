//		LeetCode Problem 7 :
/*
Given a 32-bit signed integer, reverse digits of an integer.

Example 1:

Input: 123
Output:  321
Example 2:

Input: -123
Output: -321
Example 3:

Input: 120
Output: 21
*/

#include "../HeaderFiles/ReverseInteger.hpp"

int ReverseInteger::reverse(int x)
{
	bool bSign;
	int ReverseValue = 0, PositiveValue = abs(x), MultiTen = 10;
	if (x < 0)
		bSign = false;
	else
		bSign = true;
	do
	{
		if (ReverseValue > INT_MAX /10)
			return 0;
		ReverseValue = ReverseValue*MultiTen + PositiveValue % MultiTen;
		PositiveValue = PositiveValue / 10;
	} while (PositiveValue > 0);
	if (ReverseValue < 0)
		return 0;
	if (!bSign)
		ReverseValue *= -1;
	return ReverseValue;
}

int ReverseInteger::reverse2(int x) 
{
    int ReverseValue = 0, Value = x;
    int MaxInt = INT_MAX / 10, MinInt = INT_MIN / 10;
    do
    {
        if (ReverseValue > MaxInt || ReverseValue < MinInt)
		    return 0;
        ReverseValue = ReverseValue*10 + Value % 10;
        Value /= 10;
    } while (Value != 0);
    return ReverseValue;
}

void ReverseInteger::Main()
{	// Test Case setting 
	int testA = 1534236469;

	//std::cout << reverse(testA) << std::endl;
	std::cout << reverse2(testA) << std::endl;	// Final
}