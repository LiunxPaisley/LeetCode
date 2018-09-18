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
    string intToRoman(int num)
    {
        vector<vector<string>> v{
            { " ", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" },
            { " ", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" },
            { " ", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" },
            { " ", "M", "MM", "MMM" }
        };

        string result = "";
        int    k      = 1000;
        int    n      = 3;
        int    a      = 0;    //
        int    b      = num;  // 1994
        for (; k > 0;)
        {
            a = b / k;
            b = b % k;
            if (a != 0)
            {
                result += v[n][a];
            }
            k = k / 10;
            n--;
        }
        return result;
    }
};

int main()
{
    int      num = 1994;
    Solution sln;
    auto     res = sln.intToRoman(num);
    cout << "res = " << res << "\n";
}