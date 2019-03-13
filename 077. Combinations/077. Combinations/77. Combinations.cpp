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
	vector<vector<int>> combine(int n, int k) {
		vector<vector<int>> result;
		vector<int> nums(n, 0);
		for (int i = 0; i < n; ++i) {
			nums[i] = i + 1;
		}
		for (int i = 0; i < n - k + 1; ++i) {
			vector<int> temp;
			temp.push_back(nums[i]);
			combine(result, nums, temp, n, k - 1, i + 1);
		}
		return result;
	}
private:
	void combine(vector<vector<int>>& result, vector<int>& nums, vector<int>& elem, int n, int k,int pos) {
		if (!k) {
			result.push_back(elem);
			return;
		}
		for (int i = pos; i < n - k + 1; ++i) {
			vector<int> temp = elem;
			temp.push_back(nums[i]);
			combine(result, nums, temp, n, k - 1, i + 1);
		}
	}
};


int main() {
	Solution sln;
	int n = 0;
	int k = 0;

	n = 4;
	
}