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
	int largestRectangleArea(vector<int>& heights) {
		stack<int> stk;
		heights.push_back(0);
		int sum = 0;
		for (int i = 0; i < heights.size(); i++) {
			if (stk.empty() || heights[i] > heights[stk.top()]) {
				stk.push(i);
			} else {
				int tmp = stk.top();
				stk.pop();
				sum = max(sum, heights[tmp] * (stk.empty() ? i : i - stk.top() - 1));
				i--;
			}
		}
		return sum;
	}
};


int main() {
	Solution sln;
	vector<int> heights;

	heights = { 2,1,5,6,2,3 };
	cout << sln.largestRectangleArea(heights) << endl;
}