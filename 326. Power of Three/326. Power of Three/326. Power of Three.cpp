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
     * Runtime: 16 ms, faster than 68.46% of C++ online submissions for Power of Three.
     * Memory Usage: 8.1 MB, less than 90.48% of C++ online submissions for Power of Three.
     */
    bool isPowerOfThree(int n) {
        return (n > 0 && 1162261467 % n == 0);
    }
    /**
     * Runtime: 24 ms, faster than 29.00% of C++ online submissions for Power of Three.
     * Memory Usage: 8.1 MB, less than 85.71% of C++ online submissions for Power of Three.
     */
    bool isPowerOfThree1(int n) {
        while (n && n % 3 == 0) {
            n /= 3;
        }
        return n == 1;
    }

};


int main() {
    Solution sln;
}