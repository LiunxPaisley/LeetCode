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
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int row = matrix.size();
		if (row == 0) {
			return false;
		} else if (row == 1) {
			for (int i = 0; i < matrix[0].size(); ++i) {
				if (matrix[0][i] == target) {
					return true;
				}
			}
			return false;
		}

		int col = matrix[0].size();
		for (int i = 0; i < row; ++i) {
			if (target <= matrix[i][col - 1]) {
				for (int j = 0; j < col; ++j) {
					if (matrix[i][j] == target) {
						return true;
					}
				}
				return false;
			}
		}
		return false;
	}
};


int main() {
	Solution sln;
	vector<vector<int>> matrix;
	int target;

	matrix = {};
	target = 3;
	cout << sln.searchMatrix(matrix, target) << endl;

	matrix = { {1,2,3,5} };
	target = 3;
	cout << sln.searchMatrix(matrix, target) << endl;

	matrix = { {3} };
	target = 3;
	cout << sln.searchMatrix(matrix, target) << endl;

	matrix = { {1,   3,  5,  7},
	{10, 11, 16, 20},
	{23, 30, 34, 50} };
	target = 3;
	cout << sln.searchMatrix(matrix, target) << endl;

	matrix = { {1,   3,  5,  7},
	{10, 11, 16, 20},
	{23, 30, 34, 50} };
	target = 13;
	cout << sln.searchMatrix(matrix, target) << endl;
}