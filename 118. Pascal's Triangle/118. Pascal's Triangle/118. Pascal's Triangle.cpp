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

void print_vector(const vector<vector<int>>& vec)
{
    for (auto&& x : vec) {
        for (auto&& y : x) {
            cout << y << " ";
        }
        cout << "\n";
    }
}

class Solution {
public:
    vector<vector<int>> generate(int numRows)
    {
        if (numRows == 0) {
            return {};
        }
        if (numRows == 1) {
            return { { 1 } };
        }
        if (numRows == 2) {
            return { { 1 }, { 1, 1 } };
        }

        vector<vector<int>> res(numRows, vector<int>(1,1));
        res[1].push_back(1);
        for (int i = 2; i < numRows; ++i) {
            for (int j = 0; j < res[i - 1].size() - 1; ++j) {
                res[i].push_back(res[i - 1][j] + res[i - 1][j + 1]);
			}
            res[i].push_back(1);
        }
        return res;
    }
};

int main()
{
    Solution sln;
    int      numRows = 0;

	numRows = 5;
    print_vector(sln.generate(numRows));
}