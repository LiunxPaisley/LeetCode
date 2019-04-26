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
     * Runtime: 20 ms, faster than 98.37% of C++ online submissions for Top K Frequent Elements.
     * Memory Usage: 11.6 MB, less than 18.79% of C++ online submissions for Top K Frequent Elements.
     */
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if (nums.empty()) return {};
        unordered_map<int, int> memo;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            memo[nums[i]]++;
        }
        typedef unordered_map<int, int>::iterator iter_type;
        vector<int> res;
        res.reserve(k);
        priority_queue<pair<int, int>> pq;
        for (iter_type iter = memo.begin(); iter != memo.end(); ++iter) {
            pq.push({ iter->second, iter->first });
            if (pq.size() > (int)memo.size() - k) {
                res.push_back(pq.top().second);
                pq.pop();
            }
        }
        // for(int i = 0; i < k; ++i){
        //     res.push_back(pq.top().second);
        //     pq.pop();
        // }
        return res;
    }
};


int main() {
    Solution sln;
}