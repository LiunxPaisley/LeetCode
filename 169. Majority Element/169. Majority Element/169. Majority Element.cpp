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
#include <cctype>

using namespace std;

class Solution {
public:
	int majorityElement(vector<int>& nums) {
		int count = 0;
		int cur = 0;
		for (int i = 0; i < nums.size(); ++i) {
			if (count == 0) {
				count++;
				cur = nums[i];
			} else if (cur == nums[i]) {
				count++;
			} else {
				count--;
			}
		}
		return cur;
	}
};


int main() {
	Solution sln;
}