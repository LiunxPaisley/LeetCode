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
	int numDistinct(string s, string t) {
		if (s == t) {
			return 1;
		}
		int len_s = s.size();
		int len_t = t.size();
		if (len_s < len_t) {
			return 0;
		}
		
		vector<vector<int>> record(len_t + 1, vector<int>(len_s + 1, 0));
		record[0][0] = 1;
		for (int i = 1; i < len_t + 1; ++i) {
			for (int j = 1; j < len_s + 1; ++j) {
				if (i <= j && t[i-1] == s[j-1]) {
					int k = j - 1;
					while (k >= 1 && record[i][k]==0) {
						--k;
					}
					int l = j - 1;
					while (l >= 1 && record[i - 1][l] == 0) {
						--l;
					}
					record[i][j] = record[i][k] + record[i - 1][l];
				}
			}
		}
		for (auto&& x : record) {
			for (auto&& y : x) {
				cout << y << " ";
			}
			cout << endl;
		}
		int k = len_s;
		while (k >= 1 && record[len_t][k] == 0) {
			--k;
		}
		return record[len_t][k];
	}
};


int main() {
	Solution sln;
	string s;
	string t;
	int result;

	s = "rabbbit", t = "rabbit";
	result = sln.numDistinct(s, t);
	cout << result << endl << endl;

	s = "babgbag", t = "bag";
	result = sln.numDistinct(s, t);
	cout << result << endl << endl;

	s = "anacondastreetracecar", t = "contra";
	result = sln.numDistinct(s, t);
	cout << result << endl << endl;
}