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
     * Runtime: 8 ms, faster than 78.72% of C++ online submissions for Ugly Number II.
     * Memory Usage: 9.8 MB, less than 82.83% of C++ online submissions for Ugly Number II.
     */
    int nthUglyNumber(int n) {
        vector<int> memo;
        memo.reserve(n);
        memo.push_back(1);
        int idx2 = 0, idx3 = 0, idx5 = 0;

        while (memo.size() < n) {
            int next2 = memo[idx2] * 2;
            int next3 = memo[idx3] * 3;
            int next5 = memo[idx5] * 5;
            int next = min(next2, min(next3, next5));
            memo.push_back(next);
            if (next == next2) { idx2++; }
            if (next == next3) { idx3++; }
            if (next == next5) { idx5++; }
        }
        return memo.back();
    }
};


int main() {
    Solution sln;
}