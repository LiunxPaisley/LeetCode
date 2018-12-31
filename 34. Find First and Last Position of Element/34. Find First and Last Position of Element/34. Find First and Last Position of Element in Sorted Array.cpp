
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

#include <cstring> 
#include <cstdio>
#include <climits>
#include <cmath>

using namespace std;

class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		int nums_size = nums.size();
		if (nums_size == 0) {
			return { -1, -1 };
		}
		vector<int> result(2, -1);

		for (int i = 0; i < nums_size; ++i) {
			if (nums[i] == target) {
				result[0] = i;

				break;
			}
		}
		for (int i = nums_size - 1; i >= 0; --i) {
			if (nums[i] == target) {
				result[1] = i;
				break;
			}
		}
		return result;
	}
};


int main() {
	Solution sln;
	vector<int> nums = { 5, 7, 7, 8, 8, 10 };
	int target = 8;
	vector<int> result = sln.searchRange(nums, target);
	for (auto&& x : result) {
		cout << x << " ";
	}
	cout << endl;
}