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
     * Runtime: 4 ms, faster than 99.56% of C++ online submissions for Largest Number.
     * Memory Usage: 9.1 MB, less than 70.88% of C++ online submissions for Largest Number.
     */
    string largestNumber(vector<int>& nums) {
        vector<string> v(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            v[i] = to_string(nums[i]);
        }
        auto comp = [](const string& a, const string& b) {
            if (a + b > b + a) {
                return true;
            } else {
                return false;
            }
        };
        sort(v.begin(), v.end(), comp);
        string res;
        for (int i = 0; i < v.size(); ++i) {
            res += v[i];
        }
        bool flag = true;
        for (int i = 0; i < res.size(); ++i) {
            if (res[i] != '0') {
                flag = false;
            }
        }
        if (flag) return "0";
        return res;
    }
};


int main() {
    Solution sln;
}