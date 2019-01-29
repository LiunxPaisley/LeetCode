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
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		multimap<string, string> mss;
		vector<vector<string>> result;
		for (int i = 0; i < strs.size(); ++i) {
			string s = strs[i];
			sort(s.begin(), s.end());
			mss.insert({ s, strs[i] });
		}
		for (multimap<string, string>::iterator iter = mss.begin(); iter != mss.end();) {
			int count = mss.count(iter->first);
			vector<string> vec;
			for (int i = 0; i < count; ++i, ++iter) {
				vec.push_back(iter->second);
			}
			result.push_back(std::move(vec));
		}
		return result;
	}
};


int main() {
	Solution sln;
	vector<string> strs;
	vector<vector<string>> result;

	strs = { "eat", "tea", "tan", "ate", "nat", "bat" };
	result = sln.groupAnagrams(strs);
	for (auto&& x : result) {
		for (auto&& y : x) {
			cout << y << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}