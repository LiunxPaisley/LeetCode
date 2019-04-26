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
     * The basic logic is:
     * i -> i & i -1 modify the right-to-left first-met 1 to 0, thus reducing the number of ones by 1
     * X..X 1 0..0 -> X..X 0 0..0, where X means 0 or 1, X..X means any numbers of X (including zero X ) 
     * i & (i - 1) 去掉了从右往左数的第一个1
     */
    vector<int> countBits(int num) {
        vector<int> res(num + 1, 0);
        for (int i = 1; i <= num; ++i) {
            res[i] = res[i & (i - 1)] + 1;
        }
        return res;
    }
    /**
     * Runtime: 56 ms, faster than 75.94% of C++ online submissions for Counting Bits.
     * Memory Usage: 9.5 MB, less than 84.12% of C++ online submissions for Counting Bits.
     */
    vector<int> countBits1(int num) {
        vector<int> res;
        res.reserve(num + 1);
        res.push_back(0);
        for (; res.size() < num + 1;) {
            int n = res.size();
            for (int i = 0; i < n; ++i) {
                res.push_back(res[i] + 1);
                if (res.size() > num) {
                    break;
                }
            }
        }
        return res;
    }
};


int main() {
    Solution sln;
}