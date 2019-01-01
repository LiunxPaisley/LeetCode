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

using namespace std;

class Solution {
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1)
        {
            return s;
        }
        int    range = 2 * numRows - 2;
        string res(s.size(), ' ');
        int    i = 0;
        int    j = 0;
        while (j < s.size())
        {
            res[i] = s[j];
            j += range;
            i++;
        }
        for (int k = 1; k < numRows - 1; k++)
        {
            j = k;
			while (j < s.size())
			{
                res[i] = s[j];
                i+=1;
                if (j + range - 2 * k < s.size())
				{
					res[i] = s[j + range - 2 * k];
                    i += 1;
				}
                j += range;
			}
        }
        j = numRows - 1;
		while (j < s.size())
		{
            res[i] = s[j];
            j += range;
            i++;
		}
        return res;
    }
};

int main()
{
    string   s       = "PAYPALISHIRING";
    int      numRows = 3;
    Solution sln;
    auto     res = sln.convert(s, numRows);
    cout << "res = " << res << ", " << (res == "PAHNAPLSIIGYIR") << "\n";

    s        = "PAYPALISHIRING";
    numRows  = 4;
    res = sln.convert(s, numRows);
    cout << "res = " << res << ", " << (res == "PINALSIGYAHRPI") << "\n";
}