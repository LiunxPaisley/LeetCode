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
     * Runtime: 8 ms, faster than 69.95% of C++ online submissions for Best Time to Buy and Sell Stock with Cooldown.
     * Memory Usage: 8.9 MB, less than 98.37% of C++ online submissions for Best Time to Buy and Sell Stock with Cooldown.
     */
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;
        // buy[i] = max(sell[i-2]-price, buy[i-1])
        // sell[i] = max(buy[i-1]+price, sell[i-1])
        // rest[i] = sell[i-1]
        vector<int> buy(prices.size(), 0);
        vector<int> sell(prices.size(), 0);
        sell[0] = 0;
        sell[1] = max(sell[0], prices[1] - prices[0]);
        buy[0] = -prices[0];
        buy[1] = max(-prices[1], buy[0]);
        for (int i = 2; i < prices.size(); ++i) {
            buy[i] = max(sell[i - 2] - prices[i], buy[i - 1]);
            sell[i] = max(buy[i - 1] + prices[i], sell[i - 1]);
        }
        return sell.back();
    }
};


int main() {
    Solution sln;
}