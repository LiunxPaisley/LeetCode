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
	int singleNumber(vector<int>& nums) {
		int res = nums[0];
		for (int i = 1; i < nums.size(); ++i) {
			res = res ^ nums[i];
		}
		return res;
	}
};


int main() {
	Solution sln;
	vector<int> nums;

	nums = { 4,1,2,1,2 };
	cout << sln.singleNumber(nums) << endl;

	nums = { 4,1,2,1,2,3,5,5,3,7,9,8,9,7,8 };
	cout << sln.singleNumber(nums) << endl;
}