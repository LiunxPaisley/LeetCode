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
     * Runtime: 196 ms, faster than 81.48% of C++ online submissions for Daily Temperatures.
     * Memory Usage: 16.1 MB, less than 49.52% of C++ online submissions for Daily Temperatures.
     */
    vector<int> dailyTemperatures(vector<int>& T) {
        if (T.empty()) return {};
        vector<int> res(T.size(), 0);
        stack<int> stk;
        for (int i = 0; i < T.size(); ++i) {
            while (!stk.empty() && T[stk.top()] < T[i]) {
                int idx = stk.top();
                stk.pop();
                res[idx] = i - idx;
            }
            stk.push(i);
        }
        return res;
    }
};


int main() {
    Solution sln;
}