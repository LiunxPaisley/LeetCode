
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
	int search(vector<int>& nums, int target) {
		int left = 0, right = nums.size() - 1;
		while (left <= right) {
			int mid = left + (right - left) / 2;
			if (nums[mid] == target) {
				return mid;
			} else if (nums[mid] < nums[right]) {
				if (nums[mid] < target && nums[right] >= target) {
                    left = mid + 1;
				} else {
					right = mid - 1;
				}
			} else {
				if (nums[left] <= target && nums[mid] > target) {
					right = mid - 1;
				} else {
					left = mid + 1;
				}
			}
		}
		return -1;
	}
};


int main() {
	Solution sln;
	vector<int> nums;
	int target = 0;
	int result = 0;

	nums = { 4, 5, 6, 7, 0, 1, 2 };
	target = 0;
	result = sln.search(nums, target);
	cout << result << endl;

	nums = { 4, 5, 6, 7, 0, 1, 2 };
	target = 3;
	result = sln.search(nums, target);
	cout << result << endl;

	nums = { 3, 1, 1 };
	target = 3;
	result = sln.search(nums, target);
	cout << result << endl;
}