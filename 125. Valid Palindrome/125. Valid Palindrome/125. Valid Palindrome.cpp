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

using namespace std;

class Solution {
public:
    bool isPalindrome(string s)
    {
        for (int i = 0, j = s.size() - 1; i < j; ++i, --j) {
            // Move 2 pointers from each end until they collide
            while (!isalnum(s[i]) && i < j)
                ++i;  // Increment left pointer if not alphanumeric
            while (!isalnum(s[j]) && i < j)
                --j;  // Decrement right pointer if no alphanumeric
            if (toupper(s[i]) != toupper(s[j]))
                return false;  // Exit and return error if not match
        }

        return true;
    }
};

int main()
{
    Solution sln;
}