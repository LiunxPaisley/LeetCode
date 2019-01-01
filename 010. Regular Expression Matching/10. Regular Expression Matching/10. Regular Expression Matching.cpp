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
    bool isMatch(string s, string p)
    {
		if (p.empty())
		{
			return s.empty();
		}  
        if (p.size() > 1 && p[1] == '*')
        {
            // a* 出现0次
            bool b1 = isMatch(s, p.substr(2));
            bool b2 = (!s.empty()) 
				&& (s[0] == p[0] || p[0] == '.') // a*出现1次
				&& isMatch(s.substr(1), p); // a*出现多次
            
            return (b1 || b2);
        }
        else
        {           
             return (!s.empty()) 
				 && (s[0] == p[0] || p[0] == '.')  // 比较当前的字符
				 && isMatch(s.substr(1), p.substr(1)); // 比较之后的字符串
        }
    }
};

int main()
{
    string   s = "aaa";
    string   p = "a*a";
    Solution sln;
    auto     res = sln.isMatch(s, p);
    cout << "res = " << (res ? "true" : "false") << "\n";
}