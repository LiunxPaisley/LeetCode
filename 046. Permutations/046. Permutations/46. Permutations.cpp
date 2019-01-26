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
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> result;
		sort(nums.begin(), nums.end());
		//int nums_size = nums.size();
		//vector<int> temp(nums_size, 0);
		permute(nums, result, 0);
		return result;
	}
private:
	void permute(vector<int>& nums, vector<vector<int>>& result, int i) {
		if (i == nums.size()) {
			result.push_back(nums);
			//return;
		}
		for (int j = i; j < nums.size(); ++j) {
			//permute(nums, result, j+1);
			swap(nums[j], nums[i]);
			permute(nums, result, i+1);
			swap(nums[j], nums[i]);
		}
	}
};


int main() {
	Solution sln;
	vector<int> nums;
	vector<vector<int>> result;

	nums = {1,2,3};
	result = sln.permute(nums);
	for (auto&& x : result) {
		for (auto&& y : x) {
			cout << y << " ";
		}
		cout << endl;
	}
	cout << endl;

	nums = {1,2,3,4,5};
	result = sln.permute(nums);
	for (auto&& x : result) {
		for (auto&& y : x) {
			cout << y << " ";
		}
		cout << endl;
	}
	cout << endl;
}