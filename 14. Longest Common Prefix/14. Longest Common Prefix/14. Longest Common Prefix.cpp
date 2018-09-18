#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <utility>
#include <memory>
#include <climits>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        if (strs.size() == 0)
            return string("");
        string& result = strs[0];
        int length = result.size();
        for (int i = 1; i < strs.size(); i++)
        {
            int j = 0;
            while (result[j] == strs[i][j] && j < length)
            {
                j++;
            }
            length = j;
        }
        return result.substr(0, length);
    }
};

int main()
{
    vector<string> s = { "flower", "flow", "flight" };
    Solution       sln;
    auto           res = sln.longestCommonPrefix(s);
    cout << "res = " << res << "\n";
}