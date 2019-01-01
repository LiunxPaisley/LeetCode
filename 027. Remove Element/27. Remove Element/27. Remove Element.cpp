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
	int removeElement(vector<int>& nums, int val) {
		int nums_size = nums.size();
		int j = 0;
		for (int i = 0; i < nums_size; ++i) {
			if (nums[i] == val) {

				continue;
			} else {
				nums[j] = nums[i];
				++j;
			}
		}
		nums.resize(j);
		return j;
	}
};


int main() {
	Solution sln;
	vector<int> nums{ 0,1,2,2,3,0,4,2 };
	int val = 2;
	int result = sln.removeElement(nums, 2);
	cout << result << endl;
	for (auto&& x : nums) {
		cout << x << " ";
	}
	cout << endl;
}