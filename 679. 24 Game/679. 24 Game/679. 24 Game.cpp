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
    bool judgePoint24(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        do {
            if (valid(nums)) return true;
        } while (next_permutation(nums.begin(), nums.end()));
        return false;
    }
private:
    bool valid(vector<int>& nums) {
        double a = nums[0], b = nums[1], c = nums[2], d = nums[3];
        if (valid(a + b, c, d) || valid(a - b, c, d) || valid(a * b, c, d) || valid(a / b, c, d)) return true;
        if (valid(a, b + c, d) || valid(a, b - c, d) || valid(a, b * c, d) || valid(a, b / c, d)) return true;
        if (valid(a, b, c + d) || valid(a, b, c - d) || valid(a, b, c * d) || valid(a, b, c / d)) return true;
        return false;
    }
    bool valid(double a, double b, double c) {
        if (valid(a + b, c) || valid(a - b, c) || valid(a * b, c) || b && valid(a / b, c)) return true;
        if (valid(a, b + c) || valid(a, b - c) || valid(a, b * c) || c && valid(a, b / c)) return true;
        return false;
    }
    bool valid(double a, double b) {
        if (abs(a + b - 24.0) < 0.0001 || abs(a - b - 24.0) < 0.0001 || abs(a * b - 24.0) < 0.0001 || b && abs(a / b - 24.0) < 0.0001)
            return true;
        return false;
    }
};


int main() {
    Solution sln;
}