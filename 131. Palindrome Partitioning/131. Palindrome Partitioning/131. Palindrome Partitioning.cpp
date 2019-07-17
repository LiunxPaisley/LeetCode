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
     * Runtime: 12 ms, faster than 92.48% of C++ online submissions for Palindrome Partitioning.
     * Memory Usage: 12.2 MB, less than 99.59% of C++ online submissions for Palindrome Partitioning.
     */
    bool is_palindrome(string& s, int f, int l) {
        while (f < l) {
            if (s[f++] != s[l--]) return false;
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> v;
        partition(s, 0, v, res);
        return res;
    }
    void partition(string& s, int f, vector<string>& v, vector<vector<string>>& res) {
        if (f >= s.size()) {
            res.push_back(v);
        }
        for (int i = f; i < s.size(); ++i) {
            if (is_palindrome(s, f, i)) {
                v.push_back(s.substr(f, i - f + 1));
                partition(s, i + 1, v, res);
                v.pop_back();
            }
        }
    }
};


int main() {
    Solution sln;
}