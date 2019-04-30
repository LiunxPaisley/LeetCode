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
     * Runtime: 84 ms, faster than 11.03% of C++ online submissions for Queue Reconstruction by Height.
     * Memory Usage: 12.6 MB, less than 5.35% of C++ online submissions for Queue Reconstruction by Height.
     */
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        auto comp = [](const vector<int> & p1, const vector<int> & p2) { return p1[0] > p2[0] || (p1[0] == p2[0] && p1[1] < p2[1]); };
        //[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
        // ---> [[7,0], [7,1], [6,1], [5,0], [5,2], [4,4]]
        sort(people.begin(), people.end(), comp);
        vector<vector<int>> res;
        // 按比自己高的人的数量插入，之前的排序保证了前面都是比自己高的人
        for (int i = 0; i < people.size(); ++i) {
            res.insert(res.begin() + people[i][1], people[i]);
        }
        return res;
    }
};


int main() {
    Solution sln;
}