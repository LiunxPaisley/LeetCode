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
     * Runtime: 36 ms, faster than 96.24% of C++ online submissions for Shortest Unsorted Continuous Subarray.
     * Memory Usage: 10.5 MB, less than 100.00% of C++ online submissions for Shortest Unsorted Continuous Subarray.
     */
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int mini = INT_MAX;
        int maxi = INT_MIN;
        int flag = false;
        for (int i = 1; i < n; ++i) {
            if (nums[i] < nums[i - 1]) {
                flag = true;
            }
            if (flag) {
                mini = min(mini, nums[i]);
            }
        }
        flag = false;
        for (int i = n - 2; i >= 0; --i) {
            if (nums[i] > nums[i + 1]) {
                flag = true;
            }
            if (flag) {
                maxi = max(maxi, nums[i]);
            }
        }
        int l = 0, r = 0;
        for (l = 0; l < n; ++l) {
            if (mini < nums[l]) {
                break;
            }
        }
        for (r = n - 1; r >= 0; --r) {
            if (maxi > nums[r]) {
                break;
            }
        }
        return r - l < 0 ? 0 : r - l + 1;
    }
};


int main() {
    Solution sln;
}