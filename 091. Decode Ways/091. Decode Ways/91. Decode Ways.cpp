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
		if (s[0] == '0') return 0;
		vector<int> rec(s.size());
		rec[0] = 1;
		for (int i = 1; i < s.size(); ++i) {

		}
		return rec.back();
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