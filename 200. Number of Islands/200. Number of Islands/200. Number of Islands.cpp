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
	 * Runtime: 16 ms, faster than 98.78% of C++ online submissions for Number of Islands.
	 * Memory Usage: 11.2 MB, less than 56.08% of C++ online submissions for Number of Islands.
	 */
	int numIslands(vector<vector<char>>& grid) {
		if (grid.empty()) return 0;
		vector<vector<char>> pad(grid.size() + 2, vector<char>(grid[0].size() + 2, 0));
		for (int i = 0; i < grid.size(); ++i) {
			for (int j = 0; j < grid[0].size(); ++j) {
				pad[i + 1][j + 1] = grid[i][j];
			}
		}
		int res = 0;
		queue<pair<int, int>> que;
		for (int i = 1; i < pad.size() - 1; ++i) {
			for (int j = 1; j < pad[0].size() - 1; ++j) {
				if (pad[i][j] == '1') {
					pad[i][j] = '2';
					que.push({ i,j });
					while (!que.empty()) {
						pair<int, int> tmp = que.front();
						que.pop();
						int x = tmp.first;
						int y = tmp.second;
						if (pad[x - 1][y] == '1') {
							pad[x - 1][y] = '2';
							que.push({ x - 1, y });
						}
						if (pad[x + 1][y] == '1') {
							pad[x + 1][y] = '2';
							que.push({ x + 1, y });
						}
						if (pad[x][y - 1] == '1') {
							pad[x][y - 1] = '2';
							que.push({ x, y - 1 });
						}
						if (pad[x][y + 1] == '1') {
							pad[x][y + 1] = '2';
							que.push({ x, y + 1 });
						}
					}
					res++;
				}
			}
		}
		return res;
	}
};


int main() {
	Solution sln;
}