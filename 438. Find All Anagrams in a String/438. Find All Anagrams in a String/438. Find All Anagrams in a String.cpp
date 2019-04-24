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
	vector<int> findAnagrams(string s, string p) {

	}
	/**
	 * Runtime: 736 ms, faster than 14.85% of C++ online submissions for Find All Anagrams in a String.
     * Memory Usage: 25.7 MB, less than 13.18% of C++ online submissions for Find All Anagrams in a String.
	 */
	vector<int> findAnagrams1(string s, string p) {
		if (s.empty()) return {};
		if (s.size() < p.size()) return {};
		vector<int> m(26, 0);
		for (int i = 0; i < p.size(); ++i) {
			m[p[i] - 'a']++;
		}
		vector<int> res;
		for (int i = 0; i < s.size() - p.size() + 1; ++i) {
			if (m[s[i] - 'a'] == 0) continue;
			vector<int> tmp = m;
			tmp[s[i] - 'a']--;
			int count = 1;
			int idx = i;
			for (int j = idx + 1; count < p.size(); ++j) {
				if (--tmp[s[j] - 'a'] < 0) break;
				count++;
			}
			if (count == p.size()) {
				res.push_back(idx);
			}
		}
		return res;
	}
};


int main() {
	Solution sln;
}