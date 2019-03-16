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
	int removeDuplicates(vector<int>& nums) {
		int size = nums.size();
		if (nums.size() < 3) return nums.size();
		int i = 0;
		int j = 0;
		int cur = nums[j];
		int count = 0;
		for (; j < size;) {
			if (cur == nums[j]) {
				nums[i] = cur;
				i++;
				j++;
				//if (j >= size) break;
				count++;
				if (count >= 2) {
					while (j < size && cur == nums[j]) {
						j++;
					}
					if (j >= size) break;
					cur = nums[j];
					count = 0;
				}
			} else {
				cur = nums[j];
				nums[i] = cur;
				i++;
				j++;
				count = 1;
			}
		}
		return i;
	}
};


int main() {
	Solution sln;
	vector<int> nums;
	int result = 0;

	nums = { 1,1,1,2,2,3 };
	result = sln.removeDuplicates(nums);
	cout << result << endl;
	for (int i = 0; i < result; ++i) {
		cout << nums[i] << " ";
	}
	cout << endl;

	nums = { 0,0,1,1,1,1,2,3,3 };
	result = sln.removeDuplicates(nums);
	cout << result << endl;
	for (int i = 0; i < result; ++i) {
		cout << nums[i] << " ";
	}
	cout << endl;

	nums = { 1,1,1,1,1,1,1,1,1 };
	result = sln.removeDuplicates(nums);
	cout << result << endl;
	for (int i = 0; i < result; ++i) {
		cout << nums[i] << " ";
	}
	cout << endl;

	nums = { 1,2,3,4,5,6,7,7,7 };
	result = sln.removeDuplicates(nums);
	cout << result << endl;
	for (int i = 0; i < result; ++i) {
		cout << nums[i] << " ";
	}
	cout << endl;
}