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
     * Runtime: 12 ms, faster than 99.01% of C++ online submissions for Find the Duplicate Number.
     * Memory Usage: 10 MB, less than 31.83% of C++ online submissions for Find the Duplicate Number.
     */
    int findDuplicate(vector<int>& nums) {
        // hashset
        // sort
        // πÍÕ√»¸≈‹£¨’“ª∑
        int hare = nums[0];
        int tortoise = nums[0];
        do {
            tortoise = nums[tortoise];
            hare = nums[nums[hare]];
        } while (tortoise != hare);

        int ptr1 = nums[0];
        int ptr2 = tortoise;
        while (ptr1 != ptr2) {
            ptr1 = nums[ptr1];
            ptr2 = nums[ptr2];
        }
        return ptr1;
    }
};


int main() {
    Solution sln;
}