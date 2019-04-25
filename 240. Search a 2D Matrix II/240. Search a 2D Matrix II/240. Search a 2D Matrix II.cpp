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
     * Runtime: 72 ms, faster than 68.57% of C++ online submissions for Search a 2D Matrix II.
     * Memory Usage: 12.9 MB, less than 44.15% of C++ online submissions for Search a 2D Matrix II.
     */
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) return false;
        int n = matrix.size();
        int m = matrix[0].size();
        int i = 0, j = m - 1;
        while (i < n && j >= 0) {
            if (matrix[i][j] == target) {
                return true;
            } else {
                if (matrix[i][j] > target) {
                    j--;
                } else {
                    i++;
                }
            }
        }
        return false;
    }
};


int main() {
    Solution sln;
}