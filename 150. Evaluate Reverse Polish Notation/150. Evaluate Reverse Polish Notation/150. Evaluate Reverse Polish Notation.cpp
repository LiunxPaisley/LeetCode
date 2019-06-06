#include <iostream>
#include <fstream>
#include <sstream>

#include <array>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <list>
#include <deque>
#include <tuple>

#include <algorithm>
#include <utility>
#include <memory>
#include <limits>
#include <functional>
#include <numeric>

#include <cstring> 
#include <cstdio>
#include <climits>
#include <cmath>
#include <cctype>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> num;
        int a = 0, b = 0;
        for (int i = 0; i < tokens.size(); ++i) {
            if (!(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")) {
                num.push(stoi(tokens[i], nullptr));
            } else {
                a = num.top(); num.pop();
                b = num.top(); num.pop();
                switch (tokens[i][0]) {
                case '+':num.push(b + a); break;
                case '-':num.push(b - a); break;
                case '*':num.push(b * a); break;
                case '/':num.push(b / a); break;
                }
            }
        }
        return num.top();
    }
};


int main() {
    Solution sln;
    vector<string> tokens{ "10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+" };
    cout << sln.evalRPN(tokens) << endl;
}