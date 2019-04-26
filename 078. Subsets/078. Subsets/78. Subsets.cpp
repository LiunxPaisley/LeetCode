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
    /**
     * Runtime: 8 ms, faster than 100.00% of C++ online submissions for Subsets.
     * Memory Usage: 9.3 MB, less than 34.75% of C++ online submissions for Subsets.
     */
    vector<vector<int>> subsets(vector<int>& nums) {
        if (nums.empty()) return {};
        int n = nums.size();
        vector<vector<int>> res;
        res.reserve(pow(2, n));
        res.push_back({});
        for (int i = 0; i < n; ++i) {
            int m = res.size();
            for (int j = 0; j < m; ++j) {
                vector<int> tmp = res[j];
                tmp.push_back(nums[i]);
                res.push_back(tmp);
            }
        }
        return res;
    }
public:
	vector<vector<int>> subsets1(vector<int>& nums) {
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