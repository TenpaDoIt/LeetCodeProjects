//      LeetCode Problem 16 :
/*
Given an array S of n integers, find three integers in S such 
that the sum is closest to a given number, target. Return the 
sum of the three integers. You may assume that each input would 
have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/

#include "../HeaderFiles/ThreeSumClosest.hpp"

int ThreeSumClosest::threeSumClosest(vector<int>& nums, int target)
{
    int ResultClosest = 10000;
    sort(nums.begin(), nums.end());
    int FirstP = 0, SecondP, ThirdP, SumP;
    while (FirstP < (nums.size()-2))
    {
        SecondP = FirstP +1;
        ThirdP = nums.size() -1;
        while ((FirstP < SecondP) && (SecondP < ThirdP))
        {
            SumP = nums[FirstP]+nums[SecondP]+nums[ThirdP]; 
            if (SumP > target)
            {
                ThirdP--;
            }
            else if(SumP < target)
            {
                SecondP++;
            }
            else
            {
                ResultClosest = SumP;
                return ResultClosest;
            }
            if (abs(SumP-target) < abs(ResultClosest-target))
                ResultClosest = SumP;
        }
        FirstP++;
    }
    return ResultClosest;
}
void ThreeSumClosest::Test()
{
    vector<int> testA(5,0);
    testA[0] = 1;
    testA[1] = 1;
    testA[2] = -1;
    testA[3] = -1;
    testA[4] = 3;
    int Result = threeSumClosest(testA, -1);

    cout << "Closest Three Sum : " << Result << endl;
}


/*  Debug Mode
int main ()
{
    ThreeSumClosest ThreeSumClosest;
    ThreeSumClosest.Test();
}
*/