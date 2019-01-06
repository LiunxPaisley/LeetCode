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
	bool isValidSudoku(vector<vector<char>>& board) {
		map<int, int> row;
		map<int, int> col;
		map<int, int> sq;
		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) {
				char c = board[i][j];
				if (c != '.') {
					for (int k = 0; k < 9; ++k) {
						char c1 = board[i][k];
						if (c1 != '.') {
							int t = ++row[c1 - '0'];
							if (t > 1) {
								return false;
							}
						}
					}
					for (int l = 0; l < 9; ++l) {
						char c2 = board[l][j];
						if (c2 != '.') {
							int t = ++col[c2 - '0'];
							if (t > 1) {
								return false;
							}
						}
					}
					row.clear();
					col.clear();
				}
			}
		}
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				for (int k = 0; k < 9; ++k) {
					char c3 = board[3 * i + k / 3][3 * j + k % 3];
					if (c3 != '.') {
						//cout << i << ' ' << j << ' ' << k << ' ' << c3 << ',';
						int t = ++sq[c3 - '0'];
						if (t > 1) {
							return false;
						}
						
					}
				}
				sq.clear();
				//cout << endl;
			}
		}
		return true;
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
	int result = sln.isValidSudoku(board);
	cout << result << endl;

	board = { {'8','3','.','.','7','.','.','.','.'},
{'6','.','.','1','9','5','.','.','.'},
{'.','9','8','.','.','.','.','6','.'},
{'8','.','.','.','6','.','.','.','3'},
{'4','.','.','8','.','3','.','.','1'},
{'7','.','.','.','2','.','.','.','6'},
{'.','6','.','.','.','.','2','8','.'},
{'.','.','.','4','1','9','.','.','5'},
{'.','.','.','.','8','.','.','7','9'} };
	result = sln.isValidSudoku(board);
	cout << result << endl;

	board = { {'.', '.', '.', '.', '5', '.', '.', '1', '.'},
			  {'.', '4', '.', '3', '.', '.', '.', '.', '.'},
			  {'.', '.', '.', '.', '.', '3', '.', '.', '1'},
			  {'8', '.', '.', '.', '.', '.', '.', '2', '.'},
			  {'.', '.', '2', '.', '7', '.', '.', '.', '.'},
			  {'.', '1', '5', '.', '.', '.', '.', '.', '.'},
			  {'.', '.', '.', '.', '.', '2', '.', '.', '.'},
			  {'.', '2', '.', '9', '.', '.', '.', '.', '.'},
			  {'.', '.', '4', '.', '.', '.', '.', '.', '.'} };
	result = sln.isValidSudoku(board);
	cout << result << endl;
}