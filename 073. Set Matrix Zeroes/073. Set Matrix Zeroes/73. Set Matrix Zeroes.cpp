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
	void setZeroes(vector<vector<int>>& matrix) {
		if (matrix.empty()) return;
		int row = matrix.size();
		int col = matrix[0].size();
		vector<pair<int, int>> record;
		for (int i = 0; i < row; ++i) {
			for (int j = 0; j < col; ++j) {
				if (!matrix[i][j]) {
					record.push_back({ i,j });
				}
			}
		}
		for (int i = 0; i < record.size(); ++i) {
			for (int x = 0; x < col; ++x) {
				matrix[record[i].first][x] = 0;
			}
			for (int y = 0; y < row; ++y) {
				matrix[y][record[i].second] = 0;
			}
		}
	}
};


int main() {
	Solution sln;
	vector<vector<int>> matrix;

	matrix = { {1,1,1},{1,0,1},{1,1,1} };
	sln.setZeroes(matrix);
	for (auto&& x : matrix) {
		for (auto&& y : x) {
			cout << y << " ";
		}
		cout << "\n";
	}

	matrix = { {0, 1, 2, 0}, { 3, 4, 5, 2 }, { 1, 3, 1, 5 }};
	sln.setZeroes(matrix);
	for (auto&& x : matrix) {
		for (auto&& y : x) {
			cout << y << " ";
		}
		cout << "\n";
	}
}