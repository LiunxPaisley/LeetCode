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

//µÚ62Ìâ£¬Runtime: 4 ms, faster than 100.00% of C++ online submissions for Unique Paths.
//	Memory Usage : 8.1 MB, less than 87.18% of C++ online submissions for Unique Paths.

class Solution {
public:
	int uniquePaths(int m, int n) {
		if (!m || !n) return 0;
		if (m == 1 || n == 1) return 1;
		//vector<vector<int>> record(n+1, vector<int>(m+1, 0));
		int record[101][101] = {0};
		record[0][1] = 1;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				record[i][j] = record[i - 1][j] + record[i][j - 1];
			}
		}

		for (auto&& x : record) {
			for (auto&& y : x) {
				cout << y << " ";
			}
			cout << "\n";
		}

		return record[n][m];
	}
};


int main() {
	Solution sln;
	int m, n;
	
	m = 3, n = 2;
	cout << sln.uniquePaths(m, n) << "\n";

	m = 7, n = 3;
	cout << sln.uniquePaths(m, n) << "\n";
}