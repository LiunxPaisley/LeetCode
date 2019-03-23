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
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		if (nums.empty()) return { {} };
		sort(nums.begin(), nums.end());
		vector<vector<int>> res{ {} };
		int count = 0;
		for (int i = 0; i < nums.size(); ++i) {
			int n = (i - 1 >= 0 && nums[i] == nums[i - 1]) ? res.size() - count: 0;
			int m = res.size();
			count = 0;
			for (int j = n; j < m; ++j) {
				vector<int> temp = res[j];
				temp.push_back(nums[i]);
				res.push_back(temp);
				++count;
			}
		}
		return res;
	}
};


int main() {
	Solution sln;
	vector<int> nums;
	vector<vector<int>> result;

	nums = { 1, 2, 2 };
	result = sln.subsetsWithDup(nums);
	cout << "result : \n";
	for (auto&& x : result) {
		for (auto&& y : x) {
			cout << y << " ";
		}
		cout << "\n";
	}
	cout << "\n";

	nums = { 1, 1 };
	result = sln.subsetsWithDup(nums);
	cout << "result : \n";
	for (auto&& x : result) {
		for (auto&& y : x) {
			cout << y << " ";
		}
		cout << "\n";
	}
	cout << "\n";


	nums = { 1, 1, 2, 3, 3, 3 };
	result = sln.subsetsWithDup(nums);
	cout << "result : \n";
	for (auto&& x : result) {
		for (auto&& y : x) {
			cout << y << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}