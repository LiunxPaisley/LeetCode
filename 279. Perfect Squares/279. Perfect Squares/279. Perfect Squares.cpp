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
     * Runtime: 80 ms, faster than 75.94% of C++ online submissions for Perfect Squares.
     * Memory Usage: 11.3 MB, less than 50.76% of C++ online submissions for Perfect Squares.
     */
    int numSquares(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            int m = sqrt(i);
            int mini = i;
            for (int j = m; j >= 1; --j) {
                mini = min(mini, 1 + dp[i - j * j]);
            }
            dp[i] = mini;
        }
        return dp[n];
    }
};


int main() {
    Solution sln;
}