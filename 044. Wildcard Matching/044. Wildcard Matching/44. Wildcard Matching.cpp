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
	bool isMatch(string s, string p) {
		int len_s = s.size();
		int len_p = p.size();
		vector<vector<bool>> rec(len_s + 1, vector<bool>(len_p + 1, false));
		rec[0][0] = true;
		for (int i = 1; i < len_p + 1; ++i) {
			if (p[i - 1] == '*') {
				rec[0][i] = rec[0][i - 1];
			}
		}
		for (int i = 1; i < len_s + 1; ++i) {
			for (int j = 1; j < len_p + 1; ++j) {
				if (p[j - 1] == '?') {
					rec[i][j] = rec[i - 1][j - 1];
				} else if (p[j - 1] == '*') {
					rec[i][j] = rec[i][j - 1] || rec[i - 1][j];
				} else {
					rec[i][j] = (s[i - 1] == p[j - 1]) && rec[i - 1][j - 1];
				}
			}
		}

		//for (auto&& x : rec) {
		//	for (auto&& y : x) {
		//		cout << y << " ";
		//	}
		//	cout << endl;
		//}

		return rec[len_s][len_p];
	}
};


int main() {
	Solution sln;
	string s;
	string p;

	s = "aa", p = "a";
	cout << sln.isMatch(s, p) << "\n\n";

	s = "aa", p = "*";
	cout << sln.isMatch(s, p) << "\n\n";

	s = "cb", p = "?a";
	cout << sln.isMatch(s, p) << "\n\n";

	s = "adceb", p = "*a*b";
	cout << sln.isMatch(s, p) << "\n\n";

	s = "acdcb", p = "a*c?b";
	cout << sln.isMatch(s, p) << "\n\n";

	s = "aaaaaa", p = "a**a?";
	cout << sln.isMatch(s, p) << "\n\n";

	s = "aaaaaa", p = "a**b?";
	cout << sln.isMatch(s, p) << "\n\n";
}