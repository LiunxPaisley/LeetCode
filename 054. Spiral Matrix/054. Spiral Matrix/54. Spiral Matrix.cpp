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
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		int m = matrix.size();
		if (m == 0) return {};
		int n = matrix[0].size();

		enum STATE { RIGHT, DOWN, LEFT, UP };
		STATE state = RIGHT;

		vector<int> result;
		result.reserve(m*n);

		int c1 = 0, c2 = n - 1;
		int r1 = 0, r2 = m - 1;
		int i = 0, j = 0;
		while (result.size() < m*n) {
			switch (state) {
			case RIGHT:
				while (j <= c2) {
					result.push_back(matrix[i][j]);
					++j;
				}
				--j;
				++i;
				++r1;
				state = DOWN;
				break;
			case DOWN:
				while (i <= r2) {
					result.push_back(matrix[i][j]);
					++i;
				}
				--i;
				--j;
				--c2;
				state = LEFT;
				break;
			case LEFT:
				while (j >= c1) {
					result.push_back(matrix[i][j]);
					--j;
				}
				++j;
				--i;
				--r2;
				state = UP;
				break;
			case UP:
				while (i >= r1) {
					result.push_back(matrix[i][j]);
					--i;
				}
				++i;
				++j;
				++c1;
				state = RIGHT;
				break;
			}
		}
		return result;
	}
};


int main() {
	Solution sln;
	vector<vector<int>> matrix;
	vector<int> result;

	matrix = { {1, 2, 3},
				{ 4, 5, 6},
				{7, 8, 9} };
	result = sln.spiralOrder(matrix);
	for (auto&& x : result) {
		cout << x << " ";
	}
	cout << "\n";

	matrix = { {1, 2, 3, 4},
				{ 5, 6, 7, 8},
				{9,10,11,12} };
	result = sln.spiralOrder(matrix);
	for (auto&& x : result) {
		cout << x << " ";
	}
	cout << "\n";
}