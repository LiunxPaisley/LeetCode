#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <utility>
#include <memory>

using namespace std;

class Solution {
public:
	int maxArea(vector<int>& height)
	{
		int h_size = height.size();
		int maxsize = 0;
		int left = 0;
		int right = h_size - 1;
		
		//int i = 1;

		maxsize = (right - left) * min(height[right], height[left]);
		while(left< right)
		{
            int t1 = (right - (left+1)) * min(height[right], height[left+1]);
			if (t1 > maxsize)
			{
                maxsize = t1;
			}
			
            int t2 = (right- 1 - left) * min(height[right-1], height[left]);
			if (t2 > maxsize)
			{
                maxsize = t2;
			} 
			left++;
			right--;
        }
        return maxsize;
    }
};

int main()
{
    vector<int> height = { 1, 8, 16, 2, 5, 4, 20, 3, 7};
    Solution    s;
    int         res = s.maxArea(height);
    cout << "res = " << res << "\n";
}