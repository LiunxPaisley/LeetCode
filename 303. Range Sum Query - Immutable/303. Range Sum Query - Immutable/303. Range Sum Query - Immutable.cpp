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

class NumArray {
public:
    /**
     * Runtime: 36 ms, faster than 51.15% of C++ online submissions for Range Sum Query - Immutable.
     * Memory Usage: 17.3 MB, less than 52.19% of C++ online submissions for Range Sum Query - Immutable.
     */
    NumArray(vector<int>& nums) {
        sum.push_back(0);
        for (int num : nums)
            sum.push_back(sum.back() + num);
    }

    int sumRange(int i, int j) {
        return sum[j + 1] - sum[i];
    }
private:
    vector<int> sum;
};


int main() {
}