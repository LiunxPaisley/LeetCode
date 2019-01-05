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
	//bool findValid(string& s, const int str_size, int i) {
	//	int j = i;
	//	stack<char> st;
	//	while (i < str_size) {
	//		if (s[i] == '(') {
	//			st.push(s[i]);
	//		} else {
	//			if (!st.empty()) {
	//				st.pop();
	//			} else {
	//				break;
	//			}
	//		}
	//		i++;
	//	}
	//}
	int longestValidParentheses(string s) {
		stack<char> st;
		int str_size = s.size();
		int max = 0;
		int i = 0;
		while (i < str_size) {
			if (s[i] == '(') {

				int flag = true;
				int res = i;
				//cout << "res = " << res << ", max = " << max << endl;
				int j = i;
				int len = 0;
				while (i < str_size && flag) {
					//cout << "i = " << i << endl;
					if (s[i] == '(') {
						st.push(s[i]);
					} else {
						if (!st.empty()) {
							st.pop();
							if (st.empty()) {
								len += i - j + 1;
								//cout << "len = " << len << endl;
								j = i + 1;
							}
						} else {
							flag = false;
						}
					}
					i += 1;
				}
				if (len > max) {
					max = len;
					
				}
				while (!st.empty()) {
					st.pop();
				}
				//cout << "res = " << res << ", max = " << max << endl;
				i = res + (len?len:1);
				//cout << ",,, i = " << i << endl;

			} else {
				i += 1;
			}
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
	
	s = "()((())()";
	result = sln.longestValidParentheses(s);
	cout << result << " " << (result == 6 ? "true" : "false") << endl;

	s = "())()()(())((()(()()(((()))((((())((()(())()())(()((((()))()(()))"
		"(())()(())(()(((((())((((((()())())(()(()((())()))(()))))))()(())"
		")((((())()()()))()()()(((()(()())(()()(()(()()(((()))))))()()))()"
		")())((()()))))))((()))(((()((())()(()()))((())))()()())))))))()))"
		"))(()))))()))()))()((())))((()))(()))))))(((()))))))))()(()()()(("
		"))((())()))()()(())))()()))(()())()))(((()())()))((())((((()))(()"
		"(()(()()()(((())()(((((()))((()(((((())(()()))((((((((()(()(()(()"
		"(())))(())(()())())(()((((()(())((()(())))(())))()(((((()(()()(()"
		")))))))())(())(())(()()(((())))((()))(((((()))))())))()((()))()))"
		"))())))))((())(((((()()))((((())))(((()(()(())())(((()(()(()()()("
		"))))())()))((()((())())()()()(((())(((((()((((((()((()())))((((()"
		")((()(((((((()(()((()()()(()(()())(()(()()((((())))()(((()())))(("
		")()))()(()()()()(((((())(()))))((()))())))()((((((()))())))()(())"
		")(())))((((()())(((((()()())(((((())(()())(()))))()(()()))())))))"
		")())))(((())(()(()()))(()))()(((())))())((((()(((()))))))()(()(()"
		"))()()(()()))))))))((()))))))(())((()((()))()))((((((()())))))(()"
		"((())((((()))))(()(()()()()(()))()()(()(()))(()()(((((((()())(())"
		"(()())((())())()(()())((())()())())(()())))())))(())())())(())((("
		")())(((()()))()))()()))()(()(())((((((((())))()((())((()((((((((("
		"(()))))(()(((((())(()(()())())))((())())))))()))(()((()()))((()(("
		"())()()()((()(())())((())())(()()(((())))))())()()(()))()())(()(("
		")((())))((((()()(())))())(())(()(()(())())())(()()())()(())())))("
		"()()(((())))((()()(((())()()(()())((((()()(()())(()((((()(()()(()"
		"(()(((()((()())(()()))(()((((()(((((()))))()()))(((()((((((()(()("
		")()()())()))(()(())))))((()(((()())())))(((()()))(()(()(((((((()("
		")))(()(())))())()(())())(())(()))(())(()))()()(()()())))))()))()("
		"(())(((()((((((((())()()))())))((()())(";
	result = sln.longestValidParentheses(s);
	cout << result << " " << (result == 6 ? "true" : "false") << endl;
}