#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <utility>
#include <functional>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s)
    {
        string::size_type str_size = s.size();
        stack<char>       st;
        for (string::size_type i = 0; i < str_size; ++i)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                st.push(s[i]);
            }
            else
            {
                if (st.empty())
                {
                    return false;
                }
                switch (st.top())
                {
                case '(':
                    if (s[i] != ')')
                    {
                        return false;
                    }
                    break;
                case '[':
                    if (s[i] != ']')
                    {
                        return false;
                    }
                    break;
                case '{':
                    if (s[i] != '}')
                    {
                        return false;
                    }
                    break;
                }
                st.pop();
            }
        }
        return st.empty()?true:false;
    }
};

int main()
{
    Solution sln;

    cout << "b1 = " << sln.isValid(string("()[]{}")) << endl;

    cout << "b2 = " << sln.isValid(string("()")) << endl;

    cout << "b3 = " << sln.isValid(string("(]")) << endl;

    cout << "b4 = " << sln.isValid(string("([)]")) << endl;

    cout << "b5 = " << sln.isValid(string("{[]}")) << endl;

    cout << "b6 = " << sln.isValid(string("[]}")) << endl;
}