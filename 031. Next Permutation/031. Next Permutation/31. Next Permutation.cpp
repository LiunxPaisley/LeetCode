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
	void nextPermutation(vector<int>& nums) {
		int nums_size = nums.size();
		int i = nums_size - 1;
		int j = nums_size - 1;
		/* 这里一定记着用大于等于，找到第一个逆降序的数字 */
		while (i > 0 && nums[i - 1] >= nums[i]) {
			i--;
		}
		i--;
		//cout << "i = " << i << endl;
		if (i >= 0) {
			while (j > 0 && nums[j] <= nums[i]) {
				j--;
			}
			//cout << "j = " << j << endl;
			swap(nums[i], nums[j]);
		}
		reverse(nums.begin() + (i + 1), nums.end());
	}
};


int main() {
	Solution sln;
	vector<int> nums{ 1,2,3 };
	sln.nextPermutation(nums);
	for (auto&& x : nums) {
		cout << x << " ";
	}
	cout << endl;

	nums = { 3, 2, 1 };
	sln.nextPermutation(nums);
	for (auto&& x : nums) {
		cout << x << " ";
	}
	cout << endl;

	nums = {1,1,5 };
	sln.nextPermutation(nums);
	for (auto&& x : nums) {
		cout << x << " ";
	}
	cout << endl;

	nums = { 1,5,1 };
	sln.nextPermutation(nums);
	for (auto&& x : nums) {
		cout << x << " ";
	}
	cout << endl;

	nums = { 5,1,1 };
	sln.nextPermutation(nums);
	for (auto&& x : nums) {
		cout << x << " ";
	}
	cout << endl;
}