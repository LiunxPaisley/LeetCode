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
     * Runtime: 8 ms, faster than 98.97% of C++ online submissions for Basic Calculator II.
     * Memory Usage: 11 MB, less than 52.45% of C++ online submissions for Basic Calculator II.
     */
    int calculate(string s) {
        int num = 0;
        int n = s.size();
        char op = '+';
        stack<int> numbers;
        for (int i = 0; i < n; ++i) {
            if (s[i] >= '0') {
                num = num * 10 + (s[i] - '0');
            }
            if ((s[i] < '0' && s[i] != ' ') || i == n - 1) {
                if (op == '+') {
                    numbers.push(num);
                }
                if (op == '-') {
                    numbers.push(-num);
                }
                if (op == '*') {
                    int t = numbers.top();
                    numbers.pop();
                    numbers.push(t * num);
                }
                if (op == '/') {
                    int t = numbers.top();
                    numbers.pop();
                    numbers.push(t / num);
                }
                op = s[i];
                num = 0;
            }
        }
        int res = 0;
        while (!numbers.empty()) {
            res += numbers.top();
            numbers.pop();
        }
        return res;
    }
};


int main() {
    Solution sln;
}