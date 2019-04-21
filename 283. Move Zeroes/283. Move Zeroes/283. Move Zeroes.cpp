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
	 * Runtime: 28 ms, faster than 11.63% of C++ online submissions for Move Zeroes.
     * Memory Usage: 9.3 MB, less than 100.00% of C++ online submissions for Move Zeroes.
	 */
	void moveZeroes(vector<int>& nums) {
		int notzero = 0;
		for (int i = 0; i < nums.size(); ++i) {
			if (nums[i]) {
				swap(nums[notzero++], nums[i]);
			}
		}
	}
	/**
	 * Runtime: 20 ms, faster than 37.28% of C++ online submissions for Move Zeroes.
	 * Memory Usage: 9.4 MB, less than 98.04% of C++ online submissions for Move Zeroes.
	 */
	void moveZeroes1(vector<int>& nums) {
		int iszero = 0;
		int notzero = 0;
		while (iszero < nums.size() && notzero < nums.size()) {
			while (iszero < nums.size() && nums[iszero] != 0) {
				iszero++;
			}
			if (iszero == nums.size()) {
				continue;
			}
			notzero = iszero + 1;
			while (notzero < nums.size() && nums[notzero] == 0) {
				notzero++;
			}
			if (notzero == nums.size()) {
				continue;
			}
			swap(nums[iszero], nums[notzero]);
			iszero++;
		}
	}
};


int main() {
	Solution sln;
}