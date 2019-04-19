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
	bool wordBreak(string s, vector<string>& wordDict) {
		unordered_set<string> st(wordDict.begin(), wordDict.end());
		//memo[i]应该定义为范围为[i,n]的子字符串是否可以拆分
		vector<int> rec(s.size(), -1);
		return search(s, 0, rec, st);
	}
private:
	bool search(string & s, size_t idx, vector<int> & rec, unordered_set<string> & st) {
		if (idx >= rec.size()) return true;
		if (rec[idx] != -1) return rec[idx];
		for (size_t i = idx + 1; i <= s.size(); ++i) {
			if (st.count(s.substr(idx, i - idx))) {
				if (search(s, i, rec, st)) {
					rec[idx] = 1;
					return rec[idx];
				}
			}
		}
		rec[idx] = 0;
		return rec[idx];
	}
};


int main() {
	Solution sln;
	string s;
	vector<string> wordDict;

	s = "leetcode";
	wordDict = { "leet", "code" };
	cout << sln.wordBreak(s, wordDict) << endl;

	s = "applepenapple";
	wordDict = { "apple", "pen" };
	cout << sln.wordBreak(s, wordDict) << endl;

	s = "catsandog";
	wordDict = { "cats", "dog", "sand", "and", "cat" };
	cout << sln.wordBreak(s, wordDict) << endl;
}