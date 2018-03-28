#include "../HeaderFiles/StringtoInteger.hpp"


unsigned int CharToValue(char c)
{
    if (c >='0' && c <= '9') { return c - '0';}
    return -1;
}

int StringtoInteger::myAtoi(string str)
{
    int ResultInt = 0;
        int SignBit = 0;
        bool GetValue = false;
        for (int i=0; i<str.size(); i++)
        {
            if (str[i] == '-')
            {
                if (SignBit == 0)
                    SignBit = -1;
                else
                    return 0;
            }
            else if (str[i] == '+')
            {
                if (SignBit == 0)
                    SignBit = 1;
                else
                    return 0;
            }
            else if (str[i] == ' ')
            {
                if (GetValue)
                    break;
                continue;
            }
            else if (CharToValue(str[i]) == -1)
            {
                if (GetValue)
                    break;
                return 0;
            }
            else
            {
                GetValue = true;
                if (SignBit == 0)
                    SignBit = 1;
                if (SignBit*ResultInt >= INT_MAX/10 || SignBit*ResultInt <= INT_MIN/10)
                {
                    if (SignBit == 1)
                    {
                        if (SignBit*ResultInt == INT_MAX/10 && CharToValue(str[i]) > 7)
                            return INT_MAX;
                        else if (SignBit*ResultInt > INT_MAX/10)
                            return INT_MAX;
                    }
                    else
                    {
                        if (SignBit*ResultInt == INT_MIN/10 && CharToValue(str[i]) > 8)
                            return INT_MIN;
                        else if (SignBit*ResultInt < INT_MIN/10)
                            return INT_MIN;
                    }
                }
                
                ResultInt = ResultInt*10 + CharToValue(str[i]);
            }
        }
        if (SignBit == 0)
            SignBit = 1;
        return SignBit*ResultInt;
}
void StringtoInteger::Test()
{
    string TestA = "      -11919730356x";
    cout << myAtoi(TestA) << endl;
}

/*  Debug Mode
int main()
{
    StringtoInteger StringtoInteger;
    StringtoInteger.Test();
}
*/