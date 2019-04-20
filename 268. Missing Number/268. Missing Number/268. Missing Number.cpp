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
	 * Runtime: 24 ms, faster than 97.98% of C++ online submissions for Missing Number.
     * Memory Usage: 9.8 MB, less than 51.37% of C++ online submissions for Missing Number. 
	 */
	int missingNumber(vector<int>& nums) {
		int res = 0;
		for (int i = 0; i < nums.size(); ++i) {
			res ^= ((i + 1) ^ nums[i]);
		}
		return res;
	}
	/**
	 * Runtime: 28 ms, faster than 39.08% of C++ online submissions for Missing Number.
	 * Memory Usage: 9.9 MB, less than 45.63% of C++ online submissions for Missing Number.
	 */
	int missingNumber1(vector<int>& nums) {
		if (nums.size() == 1) return 1 - nums[0];
		for (int i = 0; i < nums.size(); ) {
			if (nums[i] < nums.size()) {
				swap(nums[i], nums[nums[i]]);
			} else {
				i++;
				continue;
			}
			if (nums[i] == i) {
				i++;
			}
		}
		int i = 0;
		for (; i < nums.size(); ++i) {
			if (nums[i] != i) {
				break;
			}
		}
		return i;
	}
};


int main() {
	Solution sln;
}