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
     * Runtime: 4 ms, faster than 84.74% of C++ online submissions for House Robber II.
     * Memory Usage: 8.6 MB, less than 61.97% of C++ online submissions for House Robber II.
     */
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        if (nums.size() <= 3) return *max_element(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> dp(n, 0);
        vector<int> dp2(n, 0);

        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n - 1; ++i) {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        // for(auto&& x : dp) {
        //     cout << x << " ";
        // }
        // cout << endl;
        dp2[1] = nums[1];
        dp2[2] = max(nums[1], nums[2]);
        for (int i = 3; i < n; ++i) {
            dp2[i] = max(dp2[i - 2] + nums[i], dp2[i - 1]);
        }
        // for(auto&& x : dp2) {
        //     cout << x << " ";
        // }
        // cout << endl;
        return max(dp[n - 2], dp2[n - 1]);
    }
};


int main() {
    Solution sln;
}