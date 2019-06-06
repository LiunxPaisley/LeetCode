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
     * Runtime: 0 ms, faster than 100.00% of C++ online submissions for Excel Sheet Column Number.
     * Memory Usage: 8.3 MB, less than 31.93% of C++ online submissions for Excel Sheet Column Number.
     */
    int titleToNumber(string s) {
        int res = 0;
        for (int i = 0; i < s.size(); ++i) {
            res = res * 26 + (s[i] - 'A' + 1);
        }
        return res;
    }
};


int main() {
    Solution sln;
}