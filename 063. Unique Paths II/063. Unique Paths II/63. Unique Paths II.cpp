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
		int step = m + n - 1;

		int result;
		vector<vector<int>> record(m, vector<int>(0, n));
		record[0][0] = 1;
		for (int i = 0; i < step; ++i) {
				
		}
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
	
}