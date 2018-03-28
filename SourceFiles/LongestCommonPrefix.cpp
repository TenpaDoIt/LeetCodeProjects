#include "../HeaderFiles/LongestCommonPrefix.hpp"

string LongestCommonPrefix::longestCommonPrefix(vector<string>& strs) 
{
    string ResultS, CompareS;
    vector<string>::iterator it = strs.begin();
    if (strs.empty())
        return ResultS;
    CompareS = it->c_str();
    if (CompareS == "" || (strs.size()<2))
        return CompareS;
    int MaxLen = 1, i = 1;
    while(i<=CompareS.size())
    {
        for (vector<string>::iterator itS = strs.begin()+1; itS != strs.end(); itS++)
        {
            if (itS->substr(0,i).find(CompareS.substr(0, i)) == -1)
            {
                MaxLen = i-1;
                if (MaxLen == 0)
                    return "";
                return CompareS.substr(0, MaxLen);
            }
        }
        i++;
        MaxLen = i;
    }
    return CompareS.substr(0, MaxLen);
}

void LongestCommonPrefix::Test()
{
    vector<string> TestA;
    TestA.push_back("aa");
    TestA.push_back("ab");
    longestCommonPrefix(TestA);
}

/*  Debug Mode
int main()
{
    LongestCommonPrefix LongestCommonPrefix;
    LongestCommonPrefix.Test();
}
*/