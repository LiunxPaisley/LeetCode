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

using namespace std;

class Solution {
public:
	bool search(vector<int>& nums, int target) {
		//return _search(nums, 0, nums.size() - 1, target);
		int left = 0;
		int right = nums.size() - 1;
		while (left <= right) {			
			while (left < right && nums[left + 1] == nums[left]) {
				++left;
			}
			while (left < right && nums[right - 1] == nums[right]) {
				--right;
			}
			int mid = left + (right - left) / 2;
			if (target == nums[mid]) {
				return true;
			}
			if (nums[mid] < nums[right]) {
				if (nums[mid] < target && target <= nums[right]) {
					left = mid + 1;
				} else {
					right = mid - 1;
				}
			} else {
				if (nums[left] <= target && target < nums[mid]) {
					right = mid - 1;
				} else {
					left = mid + 1;
				}
			}
		}
		return false;
	}
};


int main() {
	Solution sln;
	vector<int> nums;
	int target = 0;

	nums = { 2,5,6,0,0,1,2 };
	target = 0;
	cout << sln.search(nums, target) << endl;

	nums = { 2,5,6,0,0,1,2 };
	target = 3;
	cout << sln.search(nums, target) << endl;

	nums = { 3,1,1 };
	target = 3;
	cout << sln.search(nums, target) << endl;

	nums = { 1,1,3,1 };
	target = 3;
	cout << sln.search(nums, target) << endl;

	nums = { 1,3,1,1,1 };
	target = 3;
	cout << sln.search(nums, target) << endl;
}