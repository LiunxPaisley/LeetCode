
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
	vector<int> findSubstring(string s, vector<string>& words) {
		if (s.empty() || words.empty()) return {};
		vector<int> res;
		int n = s.size(), cnt = words.size(), len = words[0].size();
		unordered_map<string, int> m1;
		for (string w : words) ++m1[w];
		for (int i = 0; i < len; ++i) {
			int left = i, count = 0;
			unordered_map<string, int> m2;
			for (int j = i; j <= n - len; j += len) {
				string t = s.substr(j, len);
				if (m1.count(t)) {
					++m2[t];
					if (m2[t] <= m1[t]) {
						++count;
					} else {
						while (m2[t] > m1[t]) {
							string t1 = s.substr(left, len);
							--m2[t1];
							if (m2[t1] < m1[t1]) --count;
							left += len;
						}
					}
					if (count == cnt) {
						res.push_back(left);
						--m2[s.substr(left, len)];
						--count;
						left += len;
					}
				} else {
					m2.clear();
					count = 0;
					left = j + len;
				}
			}
		}
		return res;
	}
};


int main() {
	Solution sln;
	
	string s = "barfoothefoobarman";
	vector<string> words{ "foo","bar" };
	vector<int> result = sln.findSubstring(s, words);
	cout << "result = ";
	for (auto&& x : result) {
		cout << x << " ";
	}
	cout << endl;

	s = "wordgoodgoodgoodbestword";
	words = { "word", "good", "best", "word" };
	result = sln.findSubstring(s, words);
	cout << "result = ";
	for (auto&& x : result) {
		cout << x << " ";
	}
	cout << endl;

	s = "foobarfoobar";
	words = { "foo","bar" };
	result = sln.findSubstring(s, words);
	cout << "result = ";
	for (auto&& x : result) {
		cout << x << " ";
	}
	cout << endl;

	s = "aaa";
	words = { "a","a" };
	result = sln.findSubstring(s, words);
	cout << "result = ";
	for (auto&& x : result) {
		cout << x << " ";
	}
	cout << endl;
}