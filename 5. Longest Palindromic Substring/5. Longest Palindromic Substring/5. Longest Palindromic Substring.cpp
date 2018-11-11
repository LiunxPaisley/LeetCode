#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;


class Solution {
public:
    bool isPalin(const string& str)
    {
        int len = str.size();
        for (int i = 0; i < len / 2; ++i)
        {
            if (str[i] != str[len - 1 - i])
            {
                return false;
            }
        }
        return true;
    }
    string longestPalindrome(string s)
    {
        if (s.size() == 1)
        {
            return s;
        }
        int    max     = 1;
        string longest = s.substr(0, 1);
        for (int i = 0; i < s.size() - 1; ++i)
        {
            for (int length = s.size() - i; length >= 2; --length)
            {
                string str = s.substr(i, length);
                if (isPalin(str))
                {
                    if (str.size() > max)
                    {
                        max     = str.size();
                        longest = str;
                        continue;
                    }
                }
            }
            if (max == s.size())
            {
                break;
            }
        }
        return longest;
    }
};


int main() {

}