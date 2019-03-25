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
	vector<string> restoreIpAddresses(string s) {
		if (s.size() < 4) return {};
		vector<string> res;
		_restore(res, s, {}, 0, 1, 1);
		_restore(res, s, {}, 0, 2, 1);
		_restore(res, s, {}, 0, 3, 1);
		return res;
	}
private:
	void _restore(vector<string>& res, string& s, string temp, int pos, int len, int count) {
		if (pos + len > s.size()) {
			return;
		}
		if (count >= 4 && pos + len < s.size()) {
			return;
		}

		int n = 0;
		for (int i = 0; i < len; ++i) {
			n = 10 * n + (s[pos + i] - '0');
		}
		//cout << count << ", " << n << endl;
		if ((len == 1 && 0 <= n && n <= 9) ||
			(len == 2 && 10 <= n && n <= 99) ||
			(len == 3 && 100 <= n && n <= 255)) {
			if (count == 4) {
				string str = temp + s.substr(pos, len);
				//cout << "str = " << str << endl;
				res.push_back(str);
				return;
			} else {
				temp += s.substr(pos, len);
				temp += ".";
				_restore(res, s, temp, pos + len, 1, count + 1);
				_restore(res, s, temp, pos + len, 2, count + 1);
				_restore(res, s, temp, pos + len, 3, count + 1);
			}
		}
	}
};


int main() {
	Solution sln;
	vector<string> res;
	string s;

	s = "25525511135";
	res = sln.restoreIpAddresses(s);
	cout << "result : ";
	for (auto&& x : res) {
		cout << x << "\n";
	}
	cout << "\n\n";
}