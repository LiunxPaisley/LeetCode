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
	int totalNQueens(int n) {
		vector<string> board(n, string(n, '.'));
		//vector<vector<string>> result;
		int count = 0;
		next_line(0, n, board, count);
		return count;
	}
private:
	bool place(int i, int j, int n, vector<string>& board) {
		for (int k = 0; k < n; ++k) {
			if (k != j) {
				if (board[i][k] == 'Q') {
					return false;
				}
			}
		}

		for (int k = 0; k < n; ++k) {
			if (k != i) {
				if (board[k][j] == 'Q') {
					return false;
				}
			}
		}
		for (int x = i + 1, y = j + 1; 0 <= x && x < n && 0 <= y && y < n; ++x, ++y) {
			if (board[x][y] == 'Q') {
				return false;
			}
		}
		for (int x = i + 1, y = j - 1; 0 <= x && x < n && 0 <= y && y < n; ++x, --y) {
			if (board[x][y] == 'Q') {
				return false;
			}
		}
		for (int x = i - 1, y = j + 1; 0 <= x && x < n && 0 <= y && y < n; --x, ++y) {
			if (board[x][y] == 'Q') {
				return false;
			}
		}
		for (int x = i - 1, y = j - 1; 0 <= x && x < n && 0 <= y && y < n; --x, --y) {
			if (board[x][y] == 'Q') {
				return false;
			}
		}
		return true;
	}

	void next_line(int i, int n, vector<string>& board, int& count) {
		for (int j = 0; j < n; ++j) {
			if (place(i, j, n, board)) {
				board[i][j] = 'Q';
				if (i == n - 1) {
					count += 1;
				} else {
					next_line(i + 1, n, board, count);
				}
				board[i][j] = '.';
			}
		}
	}
};


int main() {
	Solution sln;
	int n;

	n = 4;
	cout << sln.totalNQueens(n) << "\n\n";

	n = 8;
	cout << sln.totalNQueens(n) << "\n\n";
}