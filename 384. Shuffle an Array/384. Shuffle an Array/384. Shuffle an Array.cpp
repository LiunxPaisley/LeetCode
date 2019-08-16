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
     * Runtime: 200 ms, faster than 84.62% of C++ online submissions for Shuffle an Array.
     * Memory Usage: 30.1 MB, less than 92.86% of C++ online submissions for Shuffle an Array.
     */
    Solution(vector<int>& nums) {
        this->nums = nums;
        tmp = nums;
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return nums;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        if (nums.empty()) return {};
        next_permutation(tmp.begin(), tmp.end());
        return tmp;
    }
private:
    vector<int> nums;
    vector<int> tmp;
};


int main() {
    Solution sln;
}