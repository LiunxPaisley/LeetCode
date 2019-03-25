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
	// best solution
	int numTrees(int n) {
		vector<int> dp(n + 1, 0);
		dp[0] = 1;
		dp[1] = 1;
		for (int i = 2; i <= n; ++i) {
			for (int j = 0; j < i; ++j) {
				dp[i] += dp[j] * dp[i - j - 1];
			}
		}
		return dp[n];
	}
	// solution2
	int numTrees2(int n) {
		if (!n) return 0;
		return count(1, n);
	}
private:
	int count(int start, int end) {
		if (start >= end) {
			return 1;
		}
		int n = 0;
		for (int i = start; i <= end; ++i) {
			int a = count(start, i - 1);
			int b = count(i + 1, end);
			n += a * b;
		}
		return n;
	}
};


int main() {
	Solution sln;

	int n = 0;

	n = 3;
	cout << sln.numTrees(n) << ", ";
	cout << sln.numTrees2(n) << endl;

	n = 18;
	cout << sln.numTrees(n) << ", ";
	cout << sln.numTrees2(n) << endl;
}