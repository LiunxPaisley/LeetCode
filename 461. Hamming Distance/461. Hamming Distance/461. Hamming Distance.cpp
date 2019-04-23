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
	/**
	 * Runtime: 4 ms, faster than 100.00% of C++ online submissions for Hamming Distance.
     * Memory Usage: 8.2 MB, less than 99.64% of C++ online submissions for Hamming Distance. 
	 */
	int hammingDistance(int x, int y) {
		int count = 0;
		int cur = 1;
		for (int i = 0; i < 31; ++i) {
			count += !!((x & cur) ^ (y & cur));
			cur = cur << 1;
		}
		return count;
	}
};


int main() {
	Solution sln;
}