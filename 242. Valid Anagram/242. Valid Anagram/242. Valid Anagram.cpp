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
     * Runtime: 8 ms, faster than 98.10% of C++ online submissions for Valid Anagram.
     * Memory Usage: 9.5 MB, less than 42.16% of C++ online submissions for Valid Anagram.
     */
    bool isAnagram(string s, string t) {
        vector<int> hs(26, 0);
        for (char ch : s) {
            hs[ch - 'a']++;
        }
        for (char ch : t) {
            hs[ch - 'a']--;
        }
        bool res = none_of(hs.begin(), hs.end(), [](int a) { return a != 0; });
        return res;
    }
};


int main() {
    Solution sln;
}