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
	int findKthLargest(vector<int>& nums, int k) {
		int left = 0;
		int right = nums.size() - 1;
		for (;;) {
			int pos = partition(nums, left, right);
			if (pos == k - 1) {
				return nums[pos];
			} else if (pos > k - 1) {
				right = pos - 1;
			} else {
				left = pos + 1;
			}
		}
	}
	int partition(vector<int>& nums, int i, int j) {
		int pivot = nums[i];
		int left = i + 1;
		int right = j;
		while (left <= right) {
			if (nums[left] < pivot && nums[right] > pivot) {
				swap(nums[left], nums[right]);
				left++;
				right--;
			}
			if (nums[left] >= pivot) left++;
			if (nums[right] <= pivot) right--;
		}
		swap(nums[i], nums[right]);
		return right;
	}
	int findKthLargest1(vector<int>& nums, int k) {
		priority_queue<int> que(nums.begin(), nums.end());
		for (int i = 0; i < k - 1; ++i) {
			que.pop();
		}
		return que.top();
	}
};

int main() {
	Solution sln;
	vector<int> nums;
	int k = 0;

	nums = { 3,2,1,5,6,4 };
	k = 2;
	cout << sln.findKthLargest(nums, k) << endl;

	nums = { 3,2,3,1,2,4,5,5,6 };
	k = 4;
	cout << sln.findKthLargest(nums, k) << endl;
}