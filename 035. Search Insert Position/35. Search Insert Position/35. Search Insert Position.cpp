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
	int searchInsert(vector<int>& nums, int target) {
		int nums_size = nums.size();
		int i = 0;
		for (; i < nums_size; ++i) {
			if (nums[i] >= target) {
				return i;
			}
		}
		return i;
	}
};


int main() {
	Solution sln;
	vector<int> nums{ 1,3,5,6 };
	int target = 2;

	int result = sln.searchInsert(nums, target);
	cout << "result = " << result << endl;

	target = 5;
	result = sln.searchInsert(nums, target);
	cout << "result = " << result << endl;

	target = 7;
	result = sln.searchInsert(nums, target);
	cout << "result = " << result << endl;

	target = 0;
	result = sln.searchInsert(nums, target);
	cout << "result = " << result << endl;
}