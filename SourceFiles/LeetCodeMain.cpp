#include "../HeaderFiles/AddTwoNumbers.hpp"
#include "../HeaderFiles/IntegertoRoman.hpp"
#include "../HeaderFiles/LongestPalindromicSubstring.hpp"
#include "../HeaderFiles/LongestSubstring.hpp"
#include "../HeaderFiles/LRUCache.hpp"
#include "../HeaderFiles/MedianofTwoSortedArrays.hpp"
#include "../HeaderFiles/ReverseInteger.hpp"
#include "../HeaderFiles/ZigZagConversion.hpp"
#include "../HeaderFiles/PalindromeNumber.hpp"
#include "../HeaderFiles/ContainerWithMostWater.hpp"
#include "../HeaderFiles/RomantoInteger.hpp"

//#include <iostream>

using namespace std;

int main(int argc, char ** argv)
{
    bool DontShowThisTime = false;
    if(DontShowThisTime)
    {
        // LeetCode 2 :
        AddTwoNumbers AddTwoNumbers;
        AddTwoNumbers.Test();
        AddTwoNumbers.~AddTwoNumbers();
        // LeetCode 3 :
        LongestSubstring LongestSubstring;
        LongestSubstring.Main();
        LongestSubstring.~LongestSubstring();
        // LeetCode 4 : Not Complete yet
        MedianTwoSortedArrays MedianTwoSortedArrays;
        MedianTwoSortedArrays.Main();
        MedianTwoSortedArrays.~MedianTwoSortedArrays();
        // LeetCode 5 :
        LongestPalindromicSubstring LongestPalindromeSubstring;
        LongestPalindromeSubstring.Main();
        LongestPalindromeSubstring.~LongestPalindromicSubstring();
        // LeetCode 6 :
        ZigZagConversion ZigZagConversion;
        ZigZagConversion.Main();
        ZigZagConversion.~ZigZagConversion();
        // LeetCode 7 :
        ReverseInteger ReverseInteger;
        ReverseInteger.Main();
        ReverseInteger.~ReverseInteger();
        // LeetCode 9 :
        PalindromeNumber PalindromeNumber;
        PalindromeNumber.Test();
        PalindromeNumber.~PalindromeNumber();
        // LeetCode 11 :
        ContainerWithMostWater ContainerWithMostWater;
        ContainerWithMostWater.Test();
        ContainerWithMostWater.~ContainerWithMostWater();
        // LeetCode 12 :
        IntegertoRoman IntegertoRoman;
        IntegertoRoman.Main();
        IntegertoRoman.~IntegertoRoman();
        // LeetCode 13 :
        RomantoInteger RomantoInteger;
        RomantoInteger.Test();
        RomantoInteger.~RomantoInteger();
        // LeetCode 146 :
        LRUCache LRUCache(2);
        LRUCache.Test();
        LRUCache.~LRUCache();
    }

    cin.get();  // Stop
    return 0;
}