#include <iostream>
#include <fstream>
#include <sstream>

#include <array>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <list>
#include <deque>
#include <tuple>

#include <algorithm>
#include <utility>
#include <memory>
#include <limits>
#include <functional>
#include <numeric>

#include <cstring> 
#include <cstdio>
#include <climits>
#include <cmath>

using namespace std;

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int max = INT_MIN, sum = 0;
		for (int i = 0; i < nums.size(); i++) {
			sum = nums[i] + (sum < 0 ? 0 : sum);
			max = sum > max ? sum : max;
		}
		return max;
	}
};


int main() {
	Solution sln;
	vector<int> nums;

	nums = { -2,1,-3,4,-1,2,1,-5,4 };
	cout << sln.maxSubArray(nums) << "\n\n";
	nums = { -2,1 };
	cout << sln.maxSubArray(nums) << "\n\n";
	nums = { 3,4,1 };
	cout << sln.maxSubArray(nums) << "\n\n";

	nums = { -3,-4,-1,-2 };
	cout << sln.maxSubArray(nums) << "\n\n";
}