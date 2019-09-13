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
     * Runtime: 0 ms, faster than 100.00% of C++ online submissions for Longest Substring with At Least K Repeating Characters.
     * Memory Usage: 8.5 MB, less than 100.00% of C++ online submissions for Longest Substring with At Least K Repeating Characters.
     */
    int longestSubstring(string s, int k) {
        return longest_core(s, 0, s.size(), k);
    }
    int longest_core(string& s, int f, int l, int k) {
        if (f >= l) return 0;
        int hs[26] = { 0 };
        for (int i = f; i < l; ++i) {
            hs[s[i] - 'a']++;
        }
        int maxlen = 0;
        for (int j = f; j < l; ++j) {
            while (j < l && hs[s[j] - 'a'] < k) ++j;
            if (j == l) break;
            int t = j + 1;
            while (t < l && hs[s[t] - 'a'] >= k) ++t;
            if (j == f && t == l) return l - f;
            maxlen = max(maxlen, longest_core(s, j, t, k));
            j = t;
        }
        return maxlen;
    }
    /**
     * Runtime: 168 ms, faster than 25.69% of C++ online submissions for Longest Substring with At Least K Repeating Characters.
     * Memory Usage: 12.5 MB, less than 27.27% of C++ online submissions for Longest Substring with At Least K Repeating Characters.
     */
    int longestSubstring1(string s, int k) {
        return longest_core(s, 0, s.size() - 1, k);
    }
    int longest_core1(string& s, int f, int l, int k) {
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
        return max(longest_core1(s, f, j - 1, k), longest_core1(s, j + 1, l, k));
    }
};


int main() {
    Solution sln;
}