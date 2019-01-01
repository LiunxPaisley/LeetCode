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
    int myAtoi(string str)
    {
        int       size = str.size();
        int       k    = 1;
        long long res  = 0;
        int       i    = 0;
        while (str[i] == ' ')
        {
            i += 1;
        }
        if (str[i] == '-' || str[i] == '+')
        {
            k = (str[i] == '+' ? 1 : -1);
            i += 1;
        }
        if ('0' > str[i] && str[i] > '9')
        {
            return 0;
        }
        while (i < size && '0' <= str[i] && str[i] <= '9')
        {
            res = res * 10 + str[i] - '0';
            if (res > INT_MAX)
            {
                return (k == 1 ? INT_MAX : INT_MIN);
            }
            i += 1;
        }
        return res * k;
    }
};

int main()
{
    string   s1 = "42";
    string   s2 = "+-2";
    string   s3 = "4193 with words";
    string   s4 = "words and 987";
    string   s5 = "-91283472332";
    Solution sln;
    int      res = sln.myAtoi(s1);
    cout << "res = " << res << "\n";
    res = sln.myAtoi(s2);
    cout << "res = " << res << "\n";
    res = sln.myAtoi(s3);
    cout << "res = " << res << "\n";
    res = sln.myAtoi(s4);
    cout << "res = " << res << "\n";
    res = sln.myAtoi(s5);
    cout << "res = " << res << "\n";
}