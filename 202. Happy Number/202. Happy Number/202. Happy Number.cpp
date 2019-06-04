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
     * Runtime: 0 ms, faster than 100.00% of C++ online submissions for Happy Number.
     * Memory Usage: 8.2 MB, less than 67.44% of C++ online submissions for Happy Number.
     */
    int next(int n) {
        int res = 0;
        while (n) {
            int tmp = n % 10;
            res += tmp * tmp;
            n = n / 10;
        }
        return res;
    }
    bool isHappy(int n) {
        int slow = n;
        int fast = next(n);
        while (slow != fast) {
            slow = next(slow);
            fast = next(next(fast));
        }
        if (slow != 1) return false;
        return true;
    }
};


int main() {
    Solution sln;
}