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

#include <cstring> 
#include <cstdio>
#include <climits>
#include <cmath>

using namespace std;

class Solution {
public:
	int longestValidParentheses(string s) {
		stack<char> st;
		int str_size = s.size();
		int max = 0;
		int i = 0;
		while (i < str_size) {
			if (s[i] == '(') {
				st.push(s[i]);
				int flag = true;
				i += 1;
				int len = 0;
				while (i < str_size && flag) {
					cout << "i = " << i << endl;
					if (s[i] == '(') {
						st.push(s[i]);
					} else if(s[i] == ')'){
						if (!st.empty()) {
							st.pop();
							len += 2;
						} else {
							flag = false;
						}
					}
					i += 1;
				}
				if (len > max) {
					max = len;
					len = 0;
				}
				while (!st.empty()) {
					st.pop();
				}
			}
			i += 1;
		}
		return max;
	}
};


int main() {
	Solution sln;
	string s = "(()";
	int result = sln.longestValidParentheses(s);
	cout << result << (result == 2 ? "true" : "false") << endl;

	s = "()(()";
	result = sln.longestValidParentheses(s);
	cout << result << " " << (result == 2 ? "true" : "false") << endl;

	s = ")()())";
	result = sln.longestValidParentheses(s);
	cout << result << " " << (result == 4 ? "true" : "false") << endl;
}