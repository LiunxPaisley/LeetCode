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
#include <cctype>

using namespace std;

class Solution {
public:
	/**
	 * Runtime: 4 ms, faster than 100.00% of C++ online submissions for House Robber.
     * Memory Usage: 8.6 MB, less than 100.00% of C++ online submissions for House Robber.
	 */
	int rob(vector<int>& nums) {
		if (nums.empty()) return 0;
		if (nums.size() == 1) return nums[0];
		/**
		 * dp[i]定义为前i项能抢到的最多的钱
		 */
		vector<int> dp(nums.size(), 0);
		dp[0] = nums[0];
		dp[1] = max(nums[0], nums[1]);
		for (int i = 2; i < nums.size(); ++i) {
			dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
		}
		return dp.back();
	}
};


int main() {
	Solution sln;
}