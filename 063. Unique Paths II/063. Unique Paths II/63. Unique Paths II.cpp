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
	
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		int m = obstacleGrid.size();
		int n = obstacleGrid[0].size();
		//int step = m + n - 1;

		if (obstacleGrid[0][0] == 1) {
			return 0;
		}
		if (obstacleGrid[m - 1][n - 1] == 1) {
			return 0;
		}
		//queue<pair<int, int>> stk;

		vector<vector<int>> record(m, vector<int>(n, 0));
		record[0][0] = 1;

		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (obstacleGrid[i][j] != 1) {
					if (j - 1 >= 0 && obstacleGrid[i][j - 1] != 1) {
						record[i][j] += record[i][j - 1];
					}
					if (i - 1 >= 0 && obstacleGrid[i - 1][j] != 1) {
						record[i][j] += record[i - 1][j];
					}
				}
			}
		}

		for (auto&& x : record) {
			for (auto&& y : x) {
				cout << y << " ";
			}
			cout << endl;
		}
		cout << endl;

		return record[m - 1][n - 1];
	}
};


int main() {
	Solution sln;
	vector<vector<int>> obstacleGrid;
	int result;

	obstacleGrid = { {0,0,0},
					 {0,1,0},
					 {0,0,0} };
	result = sln.uniquePathsWithObstacles(obstacleGrid);
	cout << result << endl;

	obstacleGrid = { {0, 0, 0, 0}, 
					{ 0, 1, 0, 0 }, 
					{ 0, 0, 0, 0 }, 
					{ 0, 0, 1, 0 }, 
					{ 0, 0, 0, 0 }};
	result = sln.uniquePathsWithObstacles(obstacleGrid);
	cout << result << endl;
	

	obstacleGrid = { {0, 1} };
	result = sln.uniquePathsWithObstacles(obstacleGrid);
	cout << result << endl;

	obstacleGrid = { {1} };
	result = sln.uniquePathsWithObstacles(obstacleGrid);
	cout << result << endl;
}