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
	// row[x][y] means: did x row have y?
	bool row[9][9];
	bool col[9][9];
	bool square[9][9];


	bool backtrace(vector<vector<char>>& board, int position) {
		int index = position;
		
		for (; index < 81 && board[index / 9][index % 9] != '.'; ++index);

		if (index < 81) {
			int r = index / 9;
			int c = index % 9;
			for (int i = 1; i < 10; ++i) {
				if (!row[r][i-1] && !col[c][i-1] && !square[(r / 3) * 3 + c / 3][i-1]) {
					board[r][c] = '0' + i;
					row[r][i-1] = true;
					col[c][i-1] = true;
					square[(r / 3) * 3 + c / 3][i-1] = true;

					if (backtrace(board, index + 1)) {
						return true;
					} else {
						board[r][c] = '.';
						row[r][i-1] = false;
						col[c][i-1] = false;
						square[(r / 3) * 3 + c / 3][i-1] = false;
					}
				}
			}
			return false;
		}
		return true;
	}

	void solveSudoku(vector<vector<char>>& board) {
		//bool row[9][9];
		//bool col[9][9];
		//bool square[9][9];
#ifdef _WIN32
		memset(row, 0, sizeof(bool) * 9 * 9);
		memset(col, 0, sizeof(bool) * 9 * 9);
		memset(square, 0, sizeof(bool) * 9 * 9);
#endif
		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) {
				if (board[i][j] != '.') {
					row[i][board[i][j] - '1'] = true;
					col[j][board[i][j] - '1'] = true;
					square[(i/3)*3 + j/3][board[i][j] - '1'] = true;
				}
			}
		}

		int count = 0;
		backtrace(board, count);
	}
};


int main() {
	Solution sln;
	vector<vector<char>> board;
	board = { {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
  {'6','.','.','1','9','5','.','.','.'},
  {'.','9','8','.','.','.','.','6','.'},
  {'8','.','.','.','6','.','.','.','3'},
  {'4','.','.','8','.','3','.','.','1'},
  {'7','.','.','.','2','.','.','.','6'},
  {'.','6','.','.','.','.','2','8','.'},
  {'.','.','.','4','1','9','.','.','5'},
  {'.','.','.','.','8','.','.','7','9'} };
	sln.solveSudoku(board);
	
	for (auto&& x : board) {
		for (auto&& y : x) {
			cout << y << " ";
		}
		cout << endl;
	}
	cout << endl;

}