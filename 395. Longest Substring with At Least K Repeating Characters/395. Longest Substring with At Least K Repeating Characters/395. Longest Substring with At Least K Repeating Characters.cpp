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
     * Runtime: 168 ms, faster than 25.69% of C++ online submissions for Longest Substring with At Least K Repeating Characters.
     * Memory Usage: 12.5 MB, less than 27.27% of C++ online submissions for Longest Substring with At Least K Repeating Characters.
     */
    int longestSubstring(string s, int k) {
        return longest_core(s, 0, s.size() - 1, k);
    }
    int longest_core(string& s, int f, int l, int k) {
        if (f > l) return 0;
        int hs[26] = { 0 };
        for (int i = f; i <= l; ++i) {
            hs[s[i] - 'a']++;
        }
        int j = f;
        for (; j <= l; ++j) {
            if (hs[s[j] - 'a'] < k) {
                break;
            }
        }
        if (j > l) return l - f + 1;
        return max(longest_core(s, f, j - 1, k), longest_core(s, j + 1, l, k));
    }
};


int main() {
    Solution sln;
}