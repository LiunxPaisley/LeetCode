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
		if (board.empty() || word.empty()) return false;
		if (word.empty()) return false;
		int row = board.size();
		int col = board[0].size();
		for (int i = 0; i < row; ++i) {
			for (int j = 0; j < col; ++j) {
				if (dfs(board, word, i, j, 0)) {
					return true;
				}
			}
		}
		return false;
	}
private:
	bool dfs(vector<vector<char>>& board, string& word, int i, int j, int pos) {
		if (pos == word.size()) {
			return true;
		}
		if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) {
			return false;
		}
		if (board[i][j] == '#') {
			return false;
		}
		if (board[i][j] != word[pos]) {
			return false;
		}
		char tmp = board[i][j];
		board[i][j] = '#';
		bool result = dfs(board, word, i + 1, j, pos + 1) ||
			dfs(board, word, i, j + 1, pos + 1) ||
			dfs(board, word, i - 1, j, pos + 1) ||
			dfs(board, word, i, j - 1, pos + 1);
		board[i][j] = tmp;
		return result;
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