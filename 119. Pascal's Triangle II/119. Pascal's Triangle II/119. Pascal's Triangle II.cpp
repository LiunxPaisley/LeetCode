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
    vector<int> getRow(int rowIndex)
    {
        if (rowIndex == 0) {
            return { 1 };
        }
        if (rowIndex == 1) {
            return { 1, 1 };
        }

        vector<vector<int>> res(rowIndex + 1, vector<int>(1, 1));
        res[1].push_back(1);
        for (int i = 2; i < rowIndex + 1; ++i) {
            for (int j = 0; j < res[i - 1].size() - 1; ++j) {
                res[i].push_back(res[i - 1][j] + res[i - 1][j + 1]);
            }
            res[i].push_back(1);
        }
        return res[rowIndex];
    }
};

int main()
{
    Solution sln;
    int      rowIndex = 3;
    vector<int> res;

	res = sln.getRow(rowIndex);
    for (auto&& x : res) {
        cout << x << " ";
	}
    cout << endl;
	
}