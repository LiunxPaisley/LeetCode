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
     * Runtime: 4 ms, faster than 100.00% of C++ online submissions for Decode String.
     * Memory Usage: 9.2 MB, less than 19.66% of C++ online submissions for Decode String.
     */
    string decodeString(string s) {
        stringstream ss(s);
        return decode_unit(ss);
    }
private:
    string decode_unit(stringstream& ss) {
        string res;
        char cur = 0;
        char tmp = 0;
        int num = 0;
        ss >> cur;
        while (!ss.eof() && cur != ']') {
            if (!isdigit(cur)) {
                res += cur;
            } else {
                ss.unget();
                ss >> num;
                ss >> tmp; // '['
                string s = decode_unit(ss);
                while (num-- > 0) {
                    res += s;
                }
            }
            ss >> cur;
        }
        return res;
    }
};


int main() {
    Solution sln;
}