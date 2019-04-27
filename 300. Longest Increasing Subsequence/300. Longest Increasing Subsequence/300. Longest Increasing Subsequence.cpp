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
     * Runtime : 4 ms, faster than 100.00% of C++ online submissions for Longest Increasing Subsequence.
     * Memory Usage : 8.8 MB, less than 18.42% of C++ online submissions for Longest Increasing Subsequence.
     */
    int lengthOfLIS(vector<int>& nums) {
        // 用当前数去替换res数组中大于等于它的数
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            vector<int>::iterator iter = std::lower_bound(res.begin(), res.end(), nums[i]);
            if (iter == res.end()) {
                res.push_back(nums[i]);
            } else {
                *iter = nums[i];
            }
        }
        return res.size();
    }
    /**
     * Runtime: 48 ms, faster than 29.31% of C++ online submissions for Longest Increasing Subsequence.
     * Memory Usage: 8.8 MB, less than 16.05% of C++ online submissions for Longest Increasing Subsequence.
     */
    int lengthOfLIS1(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int tmp = 0;
            for (int j = i - 1; j >= 0; --j) {
                if (nums[i] > nums[j]) {
                    tmp = max(tmp, dp[j]);
                }
            }
            dp[i] += tmp;
            res = max(dp[i], res);
        }
        return res;
    }
};


int main() {
    Solution sln;
}