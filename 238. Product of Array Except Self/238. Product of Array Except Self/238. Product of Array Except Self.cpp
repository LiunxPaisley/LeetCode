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
     * Runtime: 44 ms, faster than 78.03% of C++ online submissions for Product of Array Except Self.
     * Memory Usage: 12.5 MB, less than 75.22% of C++ online submissions for Product of Array Except Self.
     */
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 1);
        for (int i = 1; i < n; ++i) {
            res[i] = res[i - 1] * nums[i - 1];
        }
        int right_product = 1;
        for (int i = n - 1; i >= 0; --i) {
            res[i] = res[i] * right_product;
            right_product *= nums[i];
        }
        return res;
    }
};


int main() {
    Solution sln;
}