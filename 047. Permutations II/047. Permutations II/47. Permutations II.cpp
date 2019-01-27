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
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		vector<vector<int>> result;
		sort(nums.begin(), nums.end());
		permuteUnique(nums, result, 0);
		return result;
	}
private:
	void permuteUnique(vector<int>& nums, vector<vector<int>>& result, int k) {
		if (k == nums.size()) {
			result.push_back(nums);
		}
		for (int i = k; i < nums.size(); ++i) {
			swap(nums[i], nums[k]);
			permuteUnique(nums, result, k + 1);
			swap(nums[i], nums[k]);
			while (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
				++i;
			}
		}
	}
};


int main() {
	Solution sln;
	vector<int> nums;
	vector<vector<int>> result;

	nums = { 1,1,2 };
	result = sln.permuteUnique(nums);
	for (auto&& x : result) {
		for (auto&& y : x) {
			cout << y << " ";
		}
		cout << "\n";
	}
	cout << "\n";

	nums = { 1,2,2,4,5 };
	result = sln.permuteUnique(nums);
	for (auto&& x : result) {
		for (auto&& y : x) {
			cout << y << " ";
		}
		cout << "\n";
	}
	cout << "\n";

	/*nums = { 1,2,3,3,3,4,4,5 };
	result = sln.permuteUnique(nums);
	for (auto&& x : result) {
		for (auto&& y : x) {
			cout << y << " ";
		}
		cout << "\n";
	}
	cout << "\n";*/
}