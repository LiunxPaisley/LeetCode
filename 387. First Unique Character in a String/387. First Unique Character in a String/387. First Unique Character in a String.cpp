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
     * Runtime: 32 ms, faster than 97.48% of C++ online submissions for First Unique Character in a String.
     * Memory Usage: 12.9 MB, less than 81.25% of C++ online submissions for First Unique Character in a String.
     */
    int firstUniqChar(string s) {
        int hs[26] = { 0 };
        for (int i = 0; i < s.size(); ++i) {
            hs[s[i] - 'a']++;
        }
        int count = -1;
        for (int i = 0; i < s.size(); ++i) {
            if (hs[s[i] - 'a'] == 1) {
                count = i;
                break;
            }
        }
        return count;
    }
};


int main() {
    Solution sln;
}