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
     * Runtime: 4 ms, faster than 52.99% of C++ online submissions for Sum of Two Integers.
     * Memory Usage: 8.2 MB, less than 91.67% of C++ online submissions for Sum of Two Integers.
     */
    int getSum(int a, int b) {
        int sum = 0, in = 0;
        while (b) {
            sum = a ^ b;
            cout << "sum:" << sum << endl;
            in = (a & b & 0x7FFFFFFF) << 1;
            a = sum;
            b = in;
        }
        return sum;
    }
};


int main() {
    Solution sln;
}