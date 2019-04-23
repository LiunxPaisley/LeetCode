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
     * Runtime: 4 ms, faster than 100.00% of C++ online submissions for Jewels and Stones.
     * Memory Usage: 8.1 MB, less than 100.00% of C++ online submissions for Jewels and Stones.
     */
    int numJewelsInStones(string J, string S) {
        int hs['z' - 'A' + 1] = { 0 };
        for (int i = 0; i < J.size(); ++i) {
            hs[J[i] - 'A']++;
        }
        int res = 0;
        for (int i = 0; i < S.size(); ++i) {
            if (hs[S[i] - 'A']) {
                res++;
            }
        }
        return res;
    }
};


int main() {
    Solution sln;
}