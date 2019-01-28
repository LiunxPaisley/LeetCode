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
	void rotate(vector<vector<int>>& matrix) {
		int n = matrix.size();
		for (int i = 0; i < n - 1; ++i) {
			for (int j = 0; j < n - i - 1; ++j) {
				swap(matrix[i][j], matrix[n-j-1][n-i-1]);
			}
		}

		for (auto&& x : matrix) {
			for (auto&& y : x) {
				cout << y << " ";
			}
			cout << "\n";
		}
		cout << "\n";

		for (int i = 0; i < n / 2; ++i) {
			for (int j = 0; j < n; ++j) {
				swap(matrix[i][j], matrix[n-i-1][j]);
			}
		}
	}
};


int main() {
	Solution sln;
	vector<vector<int>> matrix;

	matrix = { {1, 2, 3},
		{4, 5, 6},
		{7, 8, 9} };
	sln.rotate(matrix);
	for (auto&& x : matrix) {
		for (auto&& y : x) {
			cout << y << " ";
		}
		cout << "\n";
	}
	cout << "\n";

	matrix = { {1, 2, 3, 4, 5},
		{6, 7, 8, 9, 10},
		{11, 12, 13, 14, 15},
	{16, 17, 18, 19, 20}, 
	{21, 22, 23, 24, 25}, };
	sln.rotate(matrix);
	for (auto&& x : matrix) {
		for (auto&& y : x) {
			cout << y << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}