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
	 * Runtime: 116 ms, faster than 96.19% of C++ online submissions for Find All Numbers Disappeared in an Array.
     * Memory Usage: 14.8 MB, less than 100.00% of C++ online submissions for Find All Numbers Disappeared in an Array. 
	 */
	vector<int> findDisappearedNumbers(vector<int>& nums) {
		vector<int> res;
		for (int i = 0; i < nums.size(); ++i) {
			int idx = abs(nums[i]) - 1;
			nums[idx] = nums[idx] > 0 ? -nums[idx] : nums[idx];
		}
		for (int i = 0; i < nums.size(); ++i) {
			if (nums[i] > 0) {
				res.push_back(i + 1);
			}
		}
		return res;
	}
};


int main() {
	Solution sln;
}