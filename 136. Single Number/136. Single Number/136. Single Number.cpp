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
		map<int, int> ht;
		for (int i = 0; i < nums.size(); ++i) {
			ht[nums[i]]++;
		}
		auto iter = ht.begin();
		for (; iter != ht.end() && iter->second != 1; ++iter);
		return iter->first;
	}
};


int main() {
	Solution sln;
	vector<int> nums;

	nums = { 4,1,2,1,2 };
	cout << sln.singleNumber(nums) << endl;
}