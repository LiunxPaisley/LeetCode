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

using namespace std;

class Solution {
public:
	int numDecodings(string s) {
		return _numDecodings(s, 0);
	}
private:
	int _numDecodings(string& s, int idx) {
		if (s[idx] == '0') return 0;
		if (idx == s.size() - 1) return 1;
		if (idx == s.size()) return 1;

		int a = _numDecodings(s, idx + 1);
		int b = 10 * (s[idx] - '0') + (s[idx + 1] - '0');
		if (b <= 26) {
			b = _numDecodings(s, idx + 2);
		} else {
			b = 0;
		}
		return a + b;

	}
};


int main() {
	Solution sln;
	string s;

	s = "0";
	cout << sln.numDecodings(s) << endl << endl;

	s = "12";
	cout << sln.numDecodings(s) << endl << endl;

	s = "226";
	cout << sln.numDecodings(s) << endl << endl;

	s = "230";
	cout << sln.numDecodings(s) << endl << endl;

	s = "1265623";
	cout << sln.numDecodings(s) << endl << endl;

	s = "120562320";
	cout << sln.numDecodings(s) << endl << endl;
}