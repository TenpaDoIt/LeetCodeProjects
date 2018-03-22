//      LeetCode Problem 13 :
/*
Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.
*/

#include "../HeaderFiles/RomantoInteger.hpp"

int RomantoInteger::romanToInt(string s) 
{
    int ResultValue = 0, i = s.size();
    while (i >= 0)
    {
        i--;
        if (s[i] == 'I')
        {
            ResultValue += 1;
        }
        if (s[i] == 'V')
        {
            ResultValue += 5;
            if (s[i-1] == 'I')
            {
                ResultValue -= 1;
                i--;
            }
        }
        if (s[i] == 'X')
        {
            ResultValue += 10;
            if (s[i-1] == 'I')
            {
                ResultValue -= 1;
                i--;
            }
        }
        if (s[i] == 'L')
        {
            ResultValue += 50;
            if (s[i-1] == 'X')
            {
                ResultValue -= 10;
                i--;
            }
        }
        if (s[i] == 'C')
        {
            ResultValue += 100;
            if (s[i-1] == 'X')
            {
                ResultValue -= 10;
                i--;
            }
        }
        if (s[i] == 'D')
        {
                ResultValue += 500;
            if (s[i-1] == 'C')
            {
                ResultValue -= 100;
                i--;
            }
        }
        if (s[i] == 'M')
        {
            ResultValue += 1000;
            if (s[i-1] == 'C')
            {
                ResultValue -= 100;
                i--;
            }
        }
    }
    return ResultValue;
}   

void RomantoInteger::Test()
{
    string TestA = "IIV";
    cout << romanToInt(TestA) << endl;
}