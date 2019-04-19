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
	void gameOfLife(vector<vector<int>>& board) {
		if (board.empty()) return;
		vector<vector<int>> pad(board.size() + 2, vector<int>(board[0].size() + 2, 0));

		int m = board.size();
		int n = board[0].size();
		for (int i = 1; i <= m; ++i) {
			for (int j = 1; j <= n; ++j) {
				pad[i][j] = board[i - 1][j - 1];
			}
		}
		vector<pair<int, int>> rec;
		for (int i = 1; i <= m; ++i) {
			for (int j = 1; j <= n; ++j) {
				int count = pad[i - 1][j - 1] + pad[i - 1][j] + pad[i - 1][j + 1]
					+ pad[i][j - 1] + pad[i][j + 1]
					+ pad[i + 1][j - 1] + pad[i + 1][j] + pad[i + 1][j + 1];
				if (pad[i][j]) {
					if (count != 2 && count != 3) {
						rec.push_back({ i, j });
					}
				} else {
					if (count == 3) {
						rec.push_back({ i, j });
					}
				}
			}
		}
		for (int i = 0; i < rec.size(); ++i) {
			board[rec[i].first - 1][rec[i].second - 1] = !pad[rec[i].first][rec[i].second];
		}
	}
};


int main() {
	Solution sln;
}