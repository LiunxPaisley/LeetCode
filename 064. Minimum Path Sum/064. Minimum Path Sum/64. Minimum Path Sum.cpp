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
	int minPathSum(vector<vector<int>>& grid) {
		int m = grid.size();
		int n = grid[0].size();
		vector<vector<int>> record(m, vector<int>(n, 0));

		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				
			}
		}
		return record[m - 1][n - 1];
	}
};


int main() {
	Solution sln;
	vector<vector<int>> grid;
	int result;

	grid = { {1,3,1},
	{1,5,1 },
	{4,2,1} };
	result = sln.minPathSum(grid);
	cout << result << endl;
}