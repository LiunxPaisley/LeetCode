#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int threeSumClosest(vector<int>& nums, int target)
    {
        sort(nums.begin(), nums.end());
        int result = 0;
        int sum = 0;
        int distance = INT_MAX;
        int i = 0, j = 0, k = 0;
        for(; i < nums.size() - 2;++i)
        {
            j  = i + 1;
            k = nums.size() - 1;
            while(j < k)
            {
                sum = nums[i] + nums[j] + nums[k];
                int temp = target - sum;
                if(temp == 0)
                {
                    return sum;
                }
                else
                {
                    int temp1 = abs(temp);
                    if(temp1 < distance)
                    {
                        distance = temp1;
                        result  = sum;
                    }
                    if(temp > 0)
                    {
                        do{
                            j++;
                        }
                        while(nums[j-1]==nums[j] && j < k);
                    }
                    else
                    {
                        do{
                            k--;
                        }
                        while(nums[k+1]==nums[k] && j < k);
                    }
                }
            }

        }
        return result;
    }
};

int main()
{
    Solution sln;
    vector<int> nums{-1, 2, 1, -4};
    int target = 1;
    int res = sln.threeSumClosest(nums, target);
    cout << "res = " << res << endl;
}
