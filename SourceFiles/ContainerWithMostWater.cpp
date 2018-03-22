//      LeetCode Problem 11 :
/*
Given n non-negative integers a1, a2, ..., an, where each represents 
a point at coordinate (i, ai). n vertical lines are drawn such that 
the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, 
which together with x-axis forms a container, such that the container 
contains the most water.

Note: You may not slant the container and n is at least 2.
*/

#include "../HeaderFiles/ContainerWithMostWater.hpp"

int ContainerWithMostWater::maxArea(vector<int>& height)
{
    int maxArea = 0, head = 0, tail = height.size()-1;
        while (head < tail)
        {
            if (height[head] <= height[tail])
            {
                maxArea = max(maxArea, height[head]*(tail-head));
                head++;
            }
            else
            {
                maxArea = max(maxArea, height[tail]*(tail-head));
                tail--;
            }
        }
        return maxArea;
}

void ContainerWithMostWater::Test()
{
    vector<int> height;
    height.push_back(1);
    height.push_back(2);
    height.push_back(1);
    
	cout << maxArea(height) << endl;
}