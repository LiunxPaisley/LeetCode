
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:

    vector<string> concat(vector<string>&& input, string digits)
    {
        static const map<int, string> m1{{2, "abc"}, {3, "def"},
            {4, "ghi"}, {5, "jkl"}, {6, "mno"},
            {7, "pqrs"}, {8, "tuv"}, {9,"wxyz"}
        };
        if(digits.size() == 0)
        {
            return input;
        }

        vector<string> start;
        vector<string> result;
        char ch = digits[0];
        map<int, string>::const_iterator iter = m1.find(ch-'0');

        string::size_type input_size = input.size();
        string::size_type iter_second_size = iter->second.size();
        for(string::size_type i = 0; i < input_size; ++i)
        {
            string s = input[i];
            for(string::size_type j = 0; j < iter_second_size; ++j)
            {
                start.push_back(s + iter->second[j]);
            }
        }

//        for(auto& item : start)
//        {
//            cout << item << " ";
//        }
//        cout << endl;

        string sub_str = digits.substr(1);
        result = concat(std::move(start), sub_str);
        return result;
    }
    vector<string> letterCombinations(string digits)
    {
        static const map<int, string> m1{{2, "abc"}, {3, "def"},
            {4, "ghi"}, {5, "jkl"}, {6, "mno"},
            {7, "pqrs"}, {8, "tuv"}, {9,"wxyz"}
        };
        if(digits.size() == 0)
        {
            return {};
        }
        vector<string> result;
        vector<string> start;
        char ch = digits[0];
        map<int, string>::const_iterator iter = m1.find(ch-'0');
        for(string::size_type i = 0; i < iter->second.size(); ++i)
        {
            string s(1, iter->second[i]);
            start.push_back(s);
        }

//        for(auto& item : start)
//        {
//            cout << item << " ";
//        }
//        cout << endl;

        string sub_str = digits.substr(1);
        result = concat(std::move(start), sub_str);
        return result;
    }
};

int main()
{
    Solution sln;
    string nums("235");
    vector<string> res = sln.letterCombinations(nums);
    cout << "res.size() = " << res.size() << endl;
    for(auto& item : res)
    {
        cout << item << " ";
    }
    cout << endl;
}
