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
	int maxProfit(vector<int>& prices) {
		if (prices.size() < 2) return 0;
		//vector<int> dp(prices.size(), 0);
		
		int min_prices = prices[0];
		int max_profit = 0;
		for (int i = 1; i < prices.size(); ++i) {
			if (prices[i] <= min_prices) {
				min_prices = prices[i];
			} else {
				int tmp = prices[i] - min_prices;
				max_profit = max(max_profit, tmp);
			}
		}
		return max_profit;
	}
};


int main() {
	Solution sln;
	vector<int> prices;

	prices = { 7,1,5,3,6,4 };
	cout << sln.maxProfit(prices) << endl;

	prices = { 7,6,4,3,1 };
	cout << sln.maxProfit(prices) << endl;
}