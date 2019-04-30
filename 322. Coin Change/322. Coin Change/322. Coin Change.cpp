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
     * Runtime: 44 ms, faster than 85.09% of C++ online submissions for Coin Change.
     * Memory Usage: 12.7 MB, less than 89.76% of C++ online submissions for Coin Change.
     */
    int coinChange(vector<int>& coins, int amount) {
        vector<int> memo(amount + 1, amount + 1);
        memo[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            for (int j = 0; j < coins.size(); ++j) {
                int rest = i - coins[j];
                if (rest >= 0) {
                    memo[i] = min(memo[i], memo[rest] + 1);
                }
            }
        }

        return memo[amount] == amount + 1 ? -1 : memo[amount];
    }
};


int main() {
    Solution sln;
}