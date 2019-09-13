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
     * Runtime: 8 ms, faster than 60.59% of C++ online submissions for Fizz Buzz.
     * Memory Usage: 9.8 MB, less than 86.67% of C++ online submissions for Fizz Buzz.
     */
    vector<string> fizzBuzz(int n) {
        vector<string> res(n, "");
        for (int i = 0; i < n; ++i) {
            if ((i + 1) % 3 == 0) {
                res[i] += "Fizz";
            }
            if ((i + 1) % 5 == 0) {
                res[i] += "Buzz";
            }
            if (res[i].empty()) {
                res[i] += to_string(i + 1);
            }
        }
        return res;
    }
};


int main() {
    Solution sln;
}