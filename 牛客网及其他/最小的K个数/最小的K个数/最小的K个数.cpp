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
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        if (input.empty() || k == 0) return {};
        if (k > input.size()) return input;
        int index = -1;
        int f = 0;
        int l = input.size() - 1;
        while (index != k - 1) {
            index = partition(input, f, l);
            for (auto&& x : input) {
                cout << x << " ";
            }
            cout << endl << index << endl;
            if (index > k - 1) {
                l = index - 1;
            } else if (index < k - 1) {
                f = index + 1;
            }
        }
        vector<int> ret(input.begin(), input.begin() + k);
        return ret;
    }
    int partition(vector<int>& input, int f, int l) {
        if (f >= l) return f;
        int m = f++;
        while (f < l) {
            while (f < l && input[f] < input[m]) f++;
            while (f < l && input[l] > input[m]) l--;
            if (f < l) {
                swap(input[f], input[l]);
            }
        }
        swap(input[m], input[--f]);
        return f;
    }
};


int main() {
    Solution sln;
    vector<int> num = { 4,5,1,6,2,7,3,8 };
    int k = 4;
    auto result = sln.GetLeastNumbers_Solution(num, k);
    for (auto&& x : result) {
        cout << x << " ";
    }
    cout << endl;
}