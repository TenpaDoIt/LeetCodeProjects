#include "../HeaderFiles/ThreeSum.hpp"

vector<vector<int> > ThreeSumZero::threeSum(vector<int>& nums)
{
    vector<vector<int> > ResultList;
    sort(nums.begin(), nums.end());
    int FirstP = 0, SecondP, ThirdP, step = 0, SumP;
    if (nums.size() < 3)
        return ResultList;
    while (nums[FirstP]<=0)
    {
        SecondP = FirstP +1;
        ThirdP = nums.size()-1;
        while((SecondP < ThirdP) && (SecondP > FirstP))
        {
            SumP = nums[FirstP]+nums[SecondP]+nums[ThirdP]; 
            if (SumP > 0)
            {
                do
                {
                    ThirdP--;
                }while (nums[ThirdP]==nums[ThirdP+1]);
            }
            else if(SumP < 0)
            {
                do
                {
                    SecondP++;
                }while(nums[SecondP] == nums[SecondP-1]);
            }
            else
            {
                vector<int> Temp(3,0);
                Temp[0] = nums[FirstP];
                Temp[1] = nums[SecondP];
                Temp[2] = nums[ThirdP];
                ResultList.push_back(Temp);
                do
                {
                    ThirdP--;
                }while (nums[ThirdP]==nums[ThirdP+1]);
                SecondP = FirstP +1;
            }
        }
        // FirstP from Negative Side
        do
        {
            FirstP++;
        }while(nums[FirstP] == nums[FirstP-1]);
    }
    return ResultList;
}


void ThreeSumZero::Test()
{
    vector<int> testA(16,0);
    testA[0] = -4;
    testA[1] = -2;
    testA[2] = 1;
    testA[3] = -5;
    testA[4] = -4;
    testA[5] = -4;
    testA[6] = 4;
    testA[7] = -2;
    testA[8] = 0;
    testA[9] = 4;
    testA[10] = 0;
    testA[11] = -2;
    testA[12] = 3;
    testA[13] = 1;
    testA[14] = -5;
    testA[15] = 0;
    vector<vector<int> > Result = threeSum(testA);

    for (vector<vector<int> >::iterator it = Result.begin(); it != Result.end(); it++ )
    {
        for (vector<int>::iterator it_inner = (*it).begin(); it_inner != (*it).end(); it_inner++ )
        {
            cout << ' ' << *it_inner;
        }
        cout << endl;
    }

}

/*int main()
{
    ThreeSumZero ThreeSumZero;
    ThreeSumZero.Test();
}*/