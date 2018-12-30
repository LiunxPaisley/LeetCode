
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
	int search(vector<int>& nums, int target) {
		int nums_size = nums.size();
		if (nums_size == 0) {
			return -1;
		}
		if (nums_size == 1) {
			if (target == nums[0]) {
				return 0;
			} else {
				return -1;
			}
		}
		int i = 0;
		int j = nums_size - 1;
		
		while(i <= j){
			int m = (i+j)/2;
			if (target == nums[m]) {
				return m;
			} else if (nums[i] <= nums[m] && nums[m] <= nums[j]) {
				if (target < nums[m]) {
					j = m - 1;
				} else {
					i = m + 1;
				}
			} else if (nums[j] <= nums[i] && nums[i] <= nums[m]) {
				if (target == nums[i]) {
					return i;
				}
				if (target < nums[i]) {
					while (nums[i + 1] > nums[i]) {
						i++;
					}
					i++;
				} else {
					while (nums[j - 1] < nums[j]) {
						j--;
					}
					j--;
				}
			} else if (nums[m] <= nums[j] && nums[j] <= nums[i]) {
				if (target == nums[j]) {
					return j;
				}
				if (target < nums[j]) {
					while (nums[i + 1] > nums[i]) {
						i++;
					}
					i++;
				} else {
					while (nums[j - 1] < nums[j]) {
						j--;
					}
					j--;
				}
			}
		}
		return -1;
	}
};


int main() {
	Solution sln;
	vector<int> nums{ 4,5,6,7,0,1,2 };
	int target = 1;
	int result = sln.search(nums, target);
	cout << result << endl;

	target = 3;
	result = sln.search(nums, target);
	cout << result << endl;
}