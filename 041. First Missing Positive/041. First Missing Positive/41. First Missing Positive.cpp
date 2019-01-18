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
	int firstMissingPositive(vector<int>& nums) {
		int nums_size = nums.size();
		/* The swap method is hard. */
		for (int i = 0; i < nums_size; ++i) {
			while (nums[i] > 0 && nums[i] <= nums_size && nums[i] != nums[nums[i]-1]) {
				swap(nums[i], nums[nums[i] - 1]);
			}
		}
		
		for (int i = 0; i < nums_size; ++i) {
			if (nums[i] != i + 1) {
				return i + 1;
			}
		}
		return nums_size + 1;
	}
};


int main() {
	Solution sln;
}