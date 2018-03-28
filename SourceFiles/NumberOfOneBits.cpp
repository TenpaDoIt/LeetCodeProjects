//      LeetCode Problem 191 :
/*
Write a function that takes an unsigned integer and returns the number 
of ’1' bits it has (also known as the Hamming weight).

For example, the 32-bit integer ’11' has binary representation 
00000000000000000000000000001011, so the function should return 3.
*/

#include "../HeaderFiles/NumberOfOneBits.hpp"

int NumberOfOneBits::hammingWeight(uint32_t n) 
{
    int Numberof1=0, base =1;
    for (int i =0; i<32; i++)
    {
        if (n & base)
            Numberof1++;
        base *= 2;
    }
    return Numberof1;
}

int NumberOfOneBits::hammingWeight2(uint32_t n) 
{
    int Numberof1=0;
    while (n != 0)
    {
        if (n % 2)
            Numberof1++;
        n /= 2;
    }
    return Numberof1;
}

int NumberOfOneBits::hammingWeight3(uint32_t n) 
{
    int Numberof1=0;
    while (n != 0)
    {
        if (n & 1)
            Numberof1++;
        n = n >> 1;
    }
    return Numberof1;
}

int NumberOfOneBits::hammingWeight4(uint32_t n) 
{
    int Numberof1=0, base =1;
    while (base <= 32)
    {
        if ((n>>base++) & 1)
            Numberof1++;
    }
    return Numberof1;
}

void NumberOfOneBits::Test()
{
    uint32_t TestA = 1;
    cout << "Method 1 : " << hammingWeight(TestA) << endl;
    cout << "Method 2 : " << hammingWeight2(TestA) << endl;
    cout << "Method 3 : " << hammingWeight3(TestA) << endl;
}

/*  Debug Mode
int main()
{
    NumberOfOneBits NumberOfOneBits;
    NumberOfOneBits.Test();
}
*/