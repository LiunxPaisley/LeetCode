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
	int climbStairs(int n) {
		vector<int> record(n + 1, 0);
		return climb(0, record, n);
	}
private:
	
	int climb(int i, vector<int>& record, int n) {
		if (i > n) {
			return 0;
		}
		if (i == n) {
			return 1;
		}
		if (record[i] > 0) {
			return record[i];
		}
		record[i] = climb(i + 1, record, n) + climb(i + 2, record, n);
		return record[i];
	}
};


int main() {
	Solution sln;
	int n;

	for (n = 1; n < 40; ++n) {
		cout << "n = " << n << ", " << sln.climbStairs(n) << "\n";
	}
}