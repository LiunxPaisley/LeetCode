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
    /**
     * Runtime : 20 ms, faster than 98.11% of C++ online submissions for Maximal Square.
     * Memory Usage : 11.2 MB, less than 65.58% of C++ online submissions for Maximal Square.
     */
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        vector<vector<int>> dp(matrix.size() + 1, vector<int>(matrix[0].size() + 1, 0));
        int res = 0;
        int row = matrix.size();
        int col = matrix[0].size();
        for (int i = 1; i <= row; ++i) {
            for (int j = 1; j <= col; ++j) {
                if (matrix[i - 1][j - 1] == '1') {
                    dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
                    res = max(res, dp[i][j]);
                }
            }
        }
        return res * res;
    }
	/**
     * Runtime: 228 ms, faster than 5.23% of C++ online submissions for Maximal Square.
     * Memory Usage: 11.3 MB, less than 65.58% of C++ online submissions for Maximal Square.
	 */
	int maximalSquare1(vector<vector<char>>& matrix) {
		if (matrix.empty()) return 0;
		int row = matrix.size();
		int col = matrix[0].size();
		vector<vector<int>> rec(row, vector<int>(col, 0));
		for (int i = 0; i < col; ++i) {
			rec[0][i] = matrix[0][i] - '0';
		}
		for (int i = 1; i < row; ++i) {
			for (int j = 0; j < col; ++j) {
				if (matrix[i][j] - '0') {
					rec[i][j] = rec[i - 1][j] + matrix[i][j] - '0';
				}
			}
		}
		for (auto&& x : rec) {
			for (auto&& y : x) {
				cout << y << " ";
			}
			cout << "\n";
		}
		int res = 0;
		for (int i = 0; i < row; ++i) {
			for (int j = 0; j < col; ++j) {
				if (rec[i][j] == 0) continue;
				for (int k = 1; k <= i + 1; ++k) {
					int flag = true;
					for (int l = j; l < j + k; ++l) {
						if (l >= col || rec[i][l] < k) {
							flag = false;
							break;
						}
					}
					if (flag) {
						res = max(res, k * k);
					}
				}
			}
		}
		return res;
	}
};


int main() {
	Solution sln;
}