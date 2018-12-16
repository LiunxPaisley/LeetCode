#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <memory>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        map<int, int> m;
        // vector<int> v;
        for (int i = 0; i < nums.size(); ++i)
        {
            m[nums[i]] = i;
        }
        for (int j = 0; j < nums.size(); ++j)
        {
            int temp = target - nums[j];
            if (m.find(temp) != m.end())
            {
                int index = m[temp];
                if (j == index)
                {
                    continue;
                }
                if (index < j)
                {
                    // v.push_back(index);
                    // v.push_back(j);
                    vector<int> v{ index, j };
                    return v;
                }
                else
                {
                    // v.push_back(j);
                    // v.push_back(index);
                    vector<int> v{ j, index };
                    return v;
                }
            }
        }
    }
};

int main()
{
    Solution    sln;
    vector<int> nums{ 8, 9, 10, 7, 6 };
    vector<int> v = sln.twoSum(nums, 9);
    for (auto& item : v)
    {
        cout << item << " ";
	}
    cout << "\n";
}