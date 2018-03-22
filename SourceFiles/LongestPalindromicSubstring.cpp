//		LeetCode Problem 5 :
/*
Given a string s, find the longest palindromic substring in s. 
You may assume that the maximum length of s is 1000.

Example:

Input: "babad"

Output: "bab"

Note: "aba" is also a valid answer.
*/
#include "../HeaderFiles/LongestPalindromicSubstring.hpp"

// First version
string LongestPalindromicSubstring::longestPalindrome(string s) 
{	
	int sStart = 0, sEnd = 0, j, maxlength = 0, CheckNumber = 0;
	int EndPos = s.length() - 1;
	int i = 0;
	while (i <= EndPos - maxlength+1)
	{	// i from the start
		j = EndPos;
		while ((j - i + 1) > maxlength)
		{	// j from the end
			if (s[j] == s[i])
			{	// if position i and j has same character
				bool bSame = true;
				CheckNumber = (j - i) / 2;
				for (int k = 0; k < CheckNumber; k++)
				{	// To Check is it not Palindromic string ?
					if (s[i + k] != s[j - k])
					{
						bSame = false;
					}
				}
				if (bSame)	// if it is Palindromic then
				{
					sStart = i;
					sEnd = j;
					maxlength = sEnd - sStart + 1;
					break;
				}
			}
			j--;
		}
		if (i + maxlength - 1 > EndPos)
		{	// For quick End purpose
			break;
		}
		i++;
	}
	return s.substr(sStart, sEnd - sStart+1);
}

string LongestPalindromicSubstring::longestPalindrome2(string s)
{	// it's look like flower
	int sStart = 0, sEnd = 0, j, maxlength = 0, distance;
	int EndPos = s.length() - 1;
	int i = 1;
	
	while (i <= EndPos - maxlength/2)
	{
		distance = 0;
		do
		{
			if (s[i+distance] == s[i-1-distance])
			{
				if (2 * (distance + 1) > maxlength)
				{
					sStart = i - 1 - distance;
					sEnd = i + distance;
					maxlength = sEnd - sStart + 1;
				}
				distance++;
			}
			else
			{
				break;
			}
		} while ((i - 1 - distance) >= 0 && (i + distance) <= EndPos);
		distance = 1;
		do
		{
			if (s[i - distance] == s[i + distance])
			{
				if (2 * distance + 1 > maxlength)
				{
					sStart = i - distance;
					sEnd = i + distance;
					maxlength = sEnd - sStart + 1;
				}
				distance++;
			}
			else
			{
				break;
			}
		} while ((i - distance) >= 0 && (i + distance) <= EndPos);
		i++;
	}
	return s.substr(sStart, sEnd - sStart + 1);
}

void LongestPalindromicSubstring::Main() {
	// Setting test Case here
	string testA = "babadada";

	std::cout << longestPalindrome2(testA).c_str() << std::endl;
}