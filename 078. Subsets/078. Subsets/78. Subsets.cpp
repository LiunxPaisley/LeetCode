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
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> result;
		result.reserve(pow(2, nums.size()));
		subsets(result, nums, {}, 0);
		return result;
	}
private:
	void subsets(vector<vector<int>>& result, vector<int>& nums, vector<int> temp, int i) {
		if (i == nums.size()) {
			result.push_back(temp);
			return;
		}
		subsets(result, nums, temp, i + 1);
		temp.push_back(nums[i]);
		subsets(result, nums, temp, i + 1);
	}
};


int main() {
	Solution sln;
	vector<int> nums;
	vector<vector<int>> result;

	nums = { 1,2,3 };
	result = sln.subsets(nums);
	for (auto&& x : result) {
		for (auto&& y : x) {
			cout << y << " ";
		}
		cout << "\n";
	}

}