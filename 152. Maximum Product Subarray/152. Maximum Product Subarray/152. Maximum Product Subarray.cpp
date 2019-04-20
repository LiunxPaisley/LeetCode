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
	int maxProduct(vector<int>& nums) {
		if (nums.empty()) return 0;
		if (nums.size() == 1) return nums[0];
		//int left = 0;
		int i = 1;

		// 分别记录以第i个数为结尾的连续子数组的最大乘积和最小乘积
		vector<int> f(nums.size(), 0);
		vector<int> g(nums.size(), 0);
		f[0] = nums[0];
		g[0] = nums[0];
		int res = f[0];
		for (; i < nums.size(); ++i) {
			f[i] = max(nums[i], max(nums[i] * f[i - 1], nums[i] * g[i - 1]));
			g[i] = min(nums[i], min(nums[i] * f[i - 1], nums[i] * g[i - 1]));
			res = max(res, f[i]);
		}

		return res;
	}
};


int main() {
	Solution sln;
}