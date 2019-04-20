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
	// sum(Positive)-sum(Negative) = target 
	// sum(Positive)+sum(Negative)+sum(Positive)-sum(Negative) = target + sum(Positive)+sum(Negative)
	// 2*sum(Positive) = target+sum(nums)
	// sum(P) = (target + sum(nums))/2
	int findTargetSumWays(vector<int>& nums, int S) {
		int sum = accumulate(nums.begin(), nums.end(), 0);
		if (sum < S) return 0;
		if ((S + sum) % 2) return 0;
		return subsetsum(nums, (S + sum) / 2);
	}
private:
	// 子数组问题
	int subsetsum(vector<int> & nums, int target) {
		vector<int> dp(target + 1, 0);
		dp[0] = 1;
		for (int i = 0; i < nums.size(); ++i) {
			for (int j = target; j >= nums[i]; --j) {
				dp[j] += dp[j - nums[i]];
			}
		}
		return dp[target];
	}
public:
	int findTargetSumWays1(vector<int>& nums, int S) {
		int res = 0;
		select(nums, 0, 0, res, S);
		return res;
	}
private:
	void select(const vector<int>& nums, int idx, int sum, int& count, int S) {
		if (idx == nums.size()) {
			if (sum == S) {
				count++;
			}
			return;
		}
		select(nums, idx + 1, sum + nums[idx], count, S);
		select(nums, idx + 1, sum - nums[idx], count, S);
	}
};


int main() {
	Solution sln;
	vector<int> nums;
	int s = 0;

	nums = {1,1,1,1,1};
	s = 3;
	cout << sln.findTargetSumWays(nums, s) << endl;
}