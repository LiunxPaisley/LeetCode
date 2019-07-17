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
     * Runtime: 16 ms, faster than 73.86% of C++ online submissions for Word Break II.
     * Memory Usage: 12.1 MB, less than 76.77% of C++ online submissions for Word Break II.
     */
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, vector<string>> memo{ {"", {""}} };
        return wordBreak(s, wordDict, memo);
    }
    vector<string> wordBreak(string s, vector<string>& wordDict, unordered_map<string, vector<string>>& memo) {
        if (memo.count(s)) return memo[s];
        vector<string> res;
        for (int i = 0; i < wordDict.size(); ++i) {
            if (s.substr(0, wordDict[i].size()) != wordDict[i]) continue;
            vector<string> ret = wordBreak(s.substr(wordDict[i].size()), wordDict, memo);
            for (int j = 0; j < ret.size(); ++j) {
                res.push_back(wordDict[i] + (ret[j].empty() ? "" : " ") + ret[j]);
            }
        }
        return memo[s] = res;
    }
};


int main() {
    Solution sln;
}