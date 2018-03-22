//		LeetCode Problem 6 :
/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a 
given number of rows like this: (you may want to display this 
pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion 
given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
*/

#include "../HeaderFiles/ZigZagConversion.hpp"

string ZigZagConversion::convert(string s, int numRows) 
{
	string converS;
	if (numRows <= 1 || s.empty())
	{
		return s;
	}
	else
	{
		int baselen = numRows * 2 - 2;
		for (int i = 0; i < numRows; i++)
		{
			for (int j = 0; j < s.length(); j++)
			{
				if ((j % baselen == i) || (j % baselen == (baselen - i)))
				{
					converS.push_back(s[j]);
				}
			}
		}
	}
	return converS;
}

void ZigZagConversion::Main()
{	// Test Case setting :
	string testA = "";

	std::cout << convert(testA, 3).c_str() << std::endl;
}