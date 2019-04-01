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
	vector<int> singleNumber(vector<int>& nums) {
		int diff = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
		diff &= -diff;
		vector<int> res(2, 0);
		for (auto &a : nums) {
			if (a & diff) res[0] ^= a;
			else res[1] ^= a;
		}
		return res;
	}
};


int main() {
	Solution sln;
}
