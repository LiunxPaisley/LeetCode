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
    bool isMatch(string s, string p) {
        int slen = s.size();
        int plen = p.size();
        int i    = 0;
        int j    = 0;
        char p_last = p[j];
		while (i < slen&&j < plen)
		{
			if (p[j+1] == '*')
			{
				while (s[i] == p_last)
				{
                    i += 1;
				}
                i += 1;
                j += 1;
			}
			if (p[j] == '.')
			{

			}

               
		}
	}
};

int main()
{
    string      s;
    string      p;
    Solution    sln;
    auto        res = sln.isMatch(s, p);
    cout << "res = " << res << "\n";
}