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
	string minWindow(string s, string t) {
		string result;
		vector<int> lettercnt(128, 0);
		for (auto&& c : t) {
			lettercnt[c] += 1;
		}
		int left = 0;
		int count = 0;
		int min_len = INT_MAX;
		for (int i = 0; i < s.size(); ++i) {
			if (--lettercnt[s[i]] >= 0) {
				count += 1;
			}
			while (count == t.size()) {
				if (min_len > i - left + 1) {
					min_len = i - left + 1;
					result = s.substr(left, min_len);
				}
				// 将子窗口的左边界向右移，如果某个移除掉的字母是T串中不可缺少的字母，
				// 那么cnt自减1，表示此时T串并没有完全匹配。
				if (++lettercnt[s[left]] > 0) --count;
				++left;
			}
		}
		return result;
	}
};


int main() {
	Solution sln;
	string s, t;
	
	s = "ADOBECODEBANC", t = "ABC";
	cout << sln.minWindow(s, t) << "\n";
}