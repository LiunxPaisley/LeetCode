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
     * Runtime: 36 ms, faster than 93.90% of C++ online submissions for Subarray Sum Equals K.
     * Memory Usage: 14.5 MB, less than 56.62% of C++ online submissions for Subarray Sum Equals K.
     */
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> hashmap;
        hashmap[0] = 1;
        int sum = 0;
        int count = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            auto iter = hashmap.find(sum - k);
            if (iter != hashmap.end()) {
                count += iter->second;
            }
            hashmap[sum] += 1;
        }
        return count;
    }
};


int main() {
    Solution sln;
}