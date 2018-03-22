//      LeetCode Problem 9 :
/*
Determine whether an integer is a palindrome. Do this without extra space.
*/

#include "../HeaderFiles/PalindromeNumber.hpp"

bool PalindromeNumber::isPalindrome(int x)
{
    int value = 0, Original = x;
        while (Original > 0)
        {
            value = value*10 + Original%10;
            Original /= 10;
        }
        if (value == x)
            return true;
        return false;
}

void PalindromeNumber::Test()
{
    int TestA = 12321;

    cout << isPalindrome(TestA) << endl;
}