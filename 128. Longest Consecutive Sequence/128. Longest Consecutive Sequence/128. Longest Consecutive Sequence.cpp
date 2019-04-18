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
	int longestConsecutive(vector<int>& nums) {
		if (nums.size() < 2) return nums.size();
		set<long long> st(nums.begin(), nums.end());
		int res = 1;
		for (int i = 0; i < nums.size(); ++i) {
			if (st.find(nums[i] - 1) == st.end()) {
				int count = 1;
				long long tmp = nums[i] + 1;
				while (st.find(tmp++) != st.end()) {
					count++;
				}
				res = max(res, count);
			}
		}
		return res;
	}
};


int main() {
	Solution sln;
	vector<int> nums;

	nums = { 100, 4, 200, 1, 3, 2 };
	cout << sln.longestConsecutive(nums) << endl;

	nums = { 2147483646,-2147483647,0,2,2147483644,-2147483645,2147483645 };
	cout << sln.longestConsecutive(nums) << endl;

}