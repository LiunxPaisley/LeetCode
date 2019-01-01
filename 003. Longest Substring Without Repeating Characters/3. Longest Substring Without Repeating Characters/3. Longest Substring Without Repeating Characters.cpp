#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        int ascii[256] = { 0 };
        int len        = 0;
        int left       = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (ascii[s[i]] == 0 || ascii[s[i]] < left)
            {
                len = max(len, i - left + 1);
            }
            else
            {
                left = ascii[s[i]];
            }
            ascii[s[i]] = i + 1;
        }
        return len;
    }
};

int main() {

}