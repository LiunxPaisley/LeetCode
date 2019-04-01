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
	int maxProfit(vector<int>& prices) {
		if (prices.empty()) return 0;
		int n = prices.size();
		vector<vector<int>> g(n, vector<int>(3, 0));
		vector<vector<int>> l(n, vector<int>(3, 0));
		for (int i = 1; i < prices.size(); ++i) {
			int diff = prices[i] - prices[i - 1];
			for (int j = 1; j <= 2; ++j) {
				l[i][j] = max(g[i - 1][j - 1] + max(diff, 0), l[i - 1][j] + diff);
				g[i][j] = max(l[i][j], g[i - 1][j]);
			}
		}
		return g[n - 1][2];
	}
};


int main() {
	Solution sln;
	vector<int> prices;
	int result;

	prices = { 3,3,5,0,0,3,1,4 };
	result = sln.maxProfit(prices);
	cout << result << endl;

	prices = { 1,2,3,4,5 };
	result = sln.maxProfit(prices);
	cout << result << endl;

	prices = { 7,6,4,3,1 };
	result = sln.maxProfit(prices);
	cout << result << endl;

	prices = { 2,1,2,0,1 };
	result = sln.maxProfit(prices);
	cout << result << endl;

}