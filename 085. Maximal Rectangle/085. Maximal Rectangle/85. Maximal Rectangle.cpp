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
	int maximalRectangle(vector<vector<char>>& matrix) {
		if (matrix.empty()) return 0;
		int row = matrix.size();
		int col = matrix[0].size();
		int res = 0;
		vector<int> heights(col + 1, 0);
		for (int i = 0; i < row; ++i) {
			for (int j = 0; j < col; ++j) {
				heights[j] = matrix[i][j] == '0' ? 0 : heights[j] + 1;
			}
			//for (auto&& x : heights) {
			//	cout << x << " ";	
			//}
			//cout << "\n";
			res = max(res, largestRectangle(heights));
		}
		return res;
	}
private:
	int largestRectangle(vector<int>& heights) {
		int size = heights.size();
		int res = 0;
		stack<int> stk;
		for (int i = 0; i < heights.size(); ++i) {
			if (stk.empty() || heights[i] > heights[stk.top()]) {
				stk.push(i);
			} else {
				int highest = stk.top();
				stk.pop();
				res = max(res, heights[highest] * (stk.empty() ? i : i - stk.top() - 1));
				--i;
			}
		}
		return res;
	}
};


int main() {
	Solution sln;
	vector<vector<char>> matrix;

	matrix = {
		{'1','0','1','0','0'},
		{'1','0','1','1','1'},
		{'1','1','1','1','1'},
		{'1','0','0','1','0'} };

	cout << sln.maximalRectangle(matrix) << endl;
}