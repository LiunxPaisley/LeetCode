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
     * Runtime: 4 ms, faster than 87.11% of C++ online submissions for Factorial Trailing Zeroes.
     * Memory Usage: 8.4 MB, less than 51.56% of C++ online submissions for Factorial Trailing Zeroes.
     */
    int trailingZeroes(int n) {
        int count = 0;
        for (long long i = 5; n / i; i *= 5)
            count += n / i;
        return count;
    }
    /**
     * Runtime: 8 ms, faster than 41.24% of C++ online submissions for Factorial Trailing Zeroes.
     * Memory Usage: 8.5 MB, less than 49.71% of C++ online submissions for Factorial Trailing Zeroes.
     */
    int trailingZeroes1(int n) {
        int res = 0;
        while (n) {
            res += n / 5;
            n /= 5;
        }
        return res;
    }
};


int main() {
    Solution sln;
    cout << sln.trailingZeroes(3) << endl;
    cout << sln.trailingZeroes(5) << endl;
    cout << sln.trailingZeroes(125) << endl;
}