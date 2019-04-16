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
	void solve(vector<vector<char>>& board) {
		if (board.empty()) return;
		int n = board.size();
		int m = board[0].size();
		if (n < 3 || m < 3) return;

		//vector<pair<int, int>> rec;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (i != 0 && i != n - 1 && j != 0 && j != m - 1) continue;
				if (board[i][j] != 'O') continue;
				board[i][j] = '#';
				queue<pair<int, int>> que;
				que.push({ i, j });
				while (!que.empty()) {
					pair<int, int> elem = que.front();
					que.pop();
					int x = elem.first;
					int y = elem.second;

					if (x >= 1 && board[x - 1][y] == 'O') {
						board[x - 1][y] = '#';
						que.push({ x - 1, y });
					}
					if (x < n - 1 && board[x + 1][y] == 'O') {
						board[x + 1][y] = '#';
						que.push({ x + 1, y });
					}
					if (y >= 1 && board[x][y - 1] == 'O') {
						board[x][y - 1] = '#';
						que.push({ x, y - 1 });
					}
					if (y < m - 1 && board[x][y + 1] == 'O') {
						board[x][y + 1] = '#';
						que.push({ x, y + 1 });
					}
				}
			}
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (board[i][j] == 'O') {
					board[i][j] = 'X';
				}
				if (board[i][j] == '#') {
					board[i][j] = 'O';
				}
			}
		}
	}
};


int main() {
	Solution sln;
	vector<vector<char>> board;
	board = { {'X', 'X', 'X', 'X'},
	{'X', 'O', 'O', 'X'},
	{'X', 'X', 'O', 'X'},
	{'X', 'O', 'X', 'X'} };
	sln.solve(board);
	for (auto&& x : board) {
		for (auto&& y : x) {
			cout << y << ' ';
		}
		cout << endl;
	}
	cout << endl;

	board = { {'X','O','O','X','X','X','O','X','O','O'},
			  {'X','O','X','X','X','X','X','X','X','X'},
			  {'X','X','X','X','O','X','X','X','X','X'},
			  {'X','O','X','X','X','O','X','X','X','O'},
			  {'O','X','X','X','O','X','O','X','O','X'},
			  {'X','X','O','X','X','O','O','X','X','X'},
			  {'O','X','X','O','O','X','O','X','X','O'},
			  {'O','X','X','X','X','X','O','X','X','X'},
			  {'X','O','O','X','X','O','X','X','O','O'},
			  {'X','X','X','O','O','X','O','X','X','O'} };
	sln.solve(board);
	for (auto&& x : board) {
		for (auto&& y : x) {
			cout << y << ' ';
		}
		cout << endl;
	}
	cout << endl;
}