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
	bool exist(vector<vector<char>>& board, string word) {
		if (board.empty()) return false;
		if (word.empty()) return false;
		int row = board.size();
		int col = board[0].size();
		for (int i = 0; i < row; ++i) {
			for (int j = 0; j < col; ++j) {
				if (board[i][j] == word[0]) {
					bool b = exist(board, word, 1, i, j + 1, 0) ||
						exist(board, word, 1, i + 1, j, 1) ||
						exist(board, word, 1, i, j - 1, 2) ||
						exist(board, word, 1, i - 1, j, 3);
					if (b) {
						return b;
					}
				}
			}
		}
		return false;
	}
private:
	bool exist(vector<vector<char>>& board, string& word, int n, int i, int j, int d) {
		if (0 <= i && i < board.size() && 0 <= j && j < board[0].size()) {

			if (board[i][j] == word[n]) {
				if (n == word.size() - 1) {
					return true;
				}
				switch (d) {
				case 0:return exist(board, word, n + 1, i, j + 1, 0) ||
					exist(board, word, n + 1, i + 1, j, 1) ||
					exist(board, word, n + 1, i - 1, j, 3);
					break;
				case 1:return exist(board, word, n + 1, i, j + 1, 0) ||
					exist(board, word, n + 1, i + 1, j, 1) ||
					exist(board, word, n + 1, i, j - 1, 2);
					break;
				case 2:return exist(board, word, n + 1, i + 1, j, 1) ||
					exist(board, word, n + 1, i, j - 1, 2) ||
					exist(board, word, n + 1, i - 1, j, 3);
					break;
				case 3:return exist(board, word, n + 1, i, j + 1, 0) ||
					exist(board, word, n + 1, i, j - 1, 2) ||
					exist(board, word, n + 1, i - 1, j, 3);
					break;
				default:
					break;
				}

			}
		}
		return false;
	}
};


int main() {
	Solution sln;
	vector<vector<char>> board;
	string word;

	board = { {'A','B','C','E' },
		{'S','F','C','S' },
		{'A','D','E','E' }
	};
	word = "ABCCED";
	cout << sln.exist(board, word) << "\n";
	word = "SEE";
	cout << sln.exist(board, word) << "\n";
	word = "ABCB";
	cout << sln.exist(board, word) << "\n";
	word = "ABCESCC";
	cout << sln.exist(board, word) << "\n";

	board = { {'a','a','a','a' },
		{'a','a','a','a' },
		{'a','a','a','a' } };
	word = "aaaaaaaaaaaaa";
	cout << sln.exist(board, word) << "\n";
}