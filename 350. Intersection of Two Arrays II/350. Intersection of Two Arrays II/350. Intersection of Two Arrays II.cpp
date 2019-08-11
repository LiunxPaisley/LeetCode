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
     * Runtime: 8 ms, faster than 75.52% of C++ online submissions for Intersection of Two Arrays II.
     * Memory Usage: 9 MB, less than 94.64% of C++ online submissions for Intersection of Two Arrays II.
     */
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> res;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j]) {
                i++;
            } else if (nums1[i] > nums2[j]) {
                j++;
            } else {
                res.push_back(nums1[i]);
                i++;
                j++;
            }
        }
        return res;
    }
};


int main() {
    Solution sln;
}