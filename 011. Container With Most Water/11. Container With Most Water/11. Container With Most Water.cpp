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

		
		while(left< right)
		{
            maxsize =
                max(maxsize, (right - left) * min(height[right], height[left]));
			if (height[left] > height[right])
			{
                right--;

			}
			else
			{
                left++;
			}
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