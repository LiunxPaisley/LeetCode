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
	int findTargetSumWays(vector<int>& nums, int S) {
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