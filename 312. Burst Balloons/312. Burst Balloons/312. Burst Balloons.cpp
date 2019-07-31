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
     * Runtime: 16 ms, faster than 90.81% of C++ online submissions for Burst Balloons.
     * Memory Usage: 9.4 MB, less than 52.02% of C++ online submissions for Burst Balloons.
     */
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        if (!n) return 0;
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        for (int len = 1; len <= n; ++len) {
            for (int left = 1; left <= n - len + 1; ++left) {
                int right = left + len - 1;
                for (int k = left; k <= right; ++k) {
                    dp[left][right] = max(dp[left][right],
                        nums[left - 1] * nums[k] * nums[right + 1] + dp[left][k - 1] + dp[k + 1][right]);
                }
            }
        }
        return dp[1][n];
    }

    map<vector<int>, int> memo;
    int maxCoins1(vector<int>& nums) {
        memo = {};
        if (nums.empty()) return 0;
        int n = nums.size();
        vector<int> pad(n + 2, 1);
        for (int i = 1; i <= n; ++i) {
            pad[i] = nums[i - 1];
        }
        return max_coins(std::move(pad));

    }
    int max_coins(vector<int> nums) {
        int maxi = 0;
        for (int i = 1; i <= nums.size() - 2; ++i) {
            int t = nums[i];
            int tmp = nums[i - 1] * nums[i] * nums[i + 1];
            nums.erase(nums.begin() + i);
            if (memo.count(nums)) {
                tmp += memo[nums];
            } else {
                tmp += max_coins(std::move(nums));
            }
            maxi = max(maxi, tmp);
            nums.insert(nums.begin() + i, t);
        }

        return memo[nums] = maxi;
    }
};


int main() {
    Solution sln;
    vector<int> nums;
    nums = { 3,1,5,8 };
    cout << sln.maxCoins(nums) << endl;

    nums = { 35,16,83,87,84,59,48,41,20,54 };
    cout << sln.maxCoins(nums) << endl;

    nums = {8, 2, 6, 8, 9, 8, 1, 4, 1, 5, 3, 0, 7, 7, 0, 4, 2};
    cout << sln.maxCoins(nums) << endl;
}