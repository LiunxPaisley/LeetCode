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
	bool canJump(vector<int>& nums) {
		int n = nums.size();
		if (n <= 1) return true;
		vector<bool> rec(n, false);
		rec[0] = true;
		for (int i = 0; i < n; ++i) {
			for (int j = 1; j <= nums[i] && i+j < n; ++j) {
				if (rec[i] == true && rec[i + j] == false) {
					rec[i + j] = true;
				}
			}
		}

		/*for (auto&& x : rec) {
			cout << x << " ";
		}
		cout << "\n";*/

		return rec.back();
	}
};


int main() {
	Solution sln;
	vector<int> nums;
	
	nums = { 2,3,1,1,4 };
	cout << sln.canJump(nums) << "\n\n";

	nums = { 3,2,1,0,4 };
	cout << sln.canJump(nums) << "\n\n";

	nums = { 0,2,3 };
	cout << sln.canJump(nums) << "\n\n";
}