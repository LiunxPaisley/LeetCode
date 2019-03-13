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
	void sortColors(vector<int>& nums) {
		int left = 0;
		int right = nums.size() - 1;
		int i = 0;
		//int count = 0;
		while (i <= right) {
			if (nums[i] == 0) {
				swap(nums[i], nums[left]);
				i++;
				left++;
			} else if (nums[i] == 1) {
				i++;
			} else {
				swap(nums[i], nums[right]);
				right--;
			}
			//for (auto&& x : nums) {
			//	cout << x << " ";
			//}
			//cout << "\n";
		}
	}
};


int main() {
	Solution sln;
	vector<int> nums;

	nums = { 2,0,2,1,1,0 };
	sln.sortColors(nums);
	for (auto&& x : nums) {
		cout << x << " ";
	}
	cout << "\n";


	nums = { 1,0,2,1,0,2,1,1,0 };
	sln.sortColors(nums);
	for (auto&& x : nums) {
		cout << x << " ";
	}
	cout << "\n";
}