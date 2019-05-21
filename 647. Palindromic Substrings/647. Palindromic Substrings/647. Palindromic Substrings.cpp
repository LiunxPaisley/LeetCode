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
     * Runtime: 4 ms, faster than 98.91% of C++ online submissions for Palindromic Substrings.
     * Memory Usage: 8.7 MB, less than 84.32% of C++ online submissions for Palindromic Substrings.
     */
    int countSubstrings(string s) {
        if (s.empty()) return 0;
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            for (int j = 0; j <= i && j <= s.size() - i - 1; ++j) {
                if (s[i + j] == s[i - j]) {
                    res++;
                } else {
                    break;
                }
            }
            if (i < s.size() - 1 && s[i] == s[i + 1]) {
                for (int j = 0; j <= i && j <= s.size() - i - 2; ++j) {
                    if (s[i + j + 1] == s[i - j]) {
                        res++;
                    } else {
                        break;
                    }
                }
            }
        }
        return res;
    }
};


int main() {
    Solution sln;
}