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
     * Runtime: 56 ms, faster than 98.82% of C++ online submissions for Sliding Window Maximum.
     * Memory Usage: 13.1 MB, less than 25.08% of C++ online submissions for Sliding Window Maximum.
     */
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        // res.reserve(nums.size() - 2);
        deque<int> dq;
        for (int i = 0; i < nums.size(); ++i) {
            // ˫����б����������������
            if (!dq.empty() && dq.front() == i - k) dq.pop_front();
            // ��β�������ȵ�ǰ��С��������������֮���Ǳ�֤dq�Ŀ�ͷ�������������
            while (!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back();
            dq.push_back(i);
            if (i >= k - 1) {
                res.push_back(nums[dq.front()]);
            }
        }
        return res;
    }
};


int main() {
    Solution sln;
}