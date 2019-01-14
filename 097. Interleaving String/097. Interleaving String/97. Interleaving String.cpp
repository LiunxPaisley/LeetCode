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
#ifndef ANSWER
	bool isInterleave(string s1, string s2, string s3) {
		int len1 = s1.size();
		int len2 = s2.size();
		int len3 = s3.size();

		if (len1 + len2 != len3) {
			return false;
		}

		vector<vector<bool>> record(len1+1, vector<bool>(len2+1, false));
		record[0][0] = true;
		for (int i = 1; i < len1 + 1; ++i) {
			record[i][0] = record[i - 1][0] && (s1[i - 1] == s3[i - 1]);
		}
		for (int i = 1; i < len2 + 1; ++i) {
			record[0][i] = record[0][i - 1] && (s2[i - 1] == s3[i - 1]);
		}
		for (int i = 1; i < len1 + 1; ++i) {
			for (int j = 1; j < len2 + 1; ++j) {
				record[i][j] = (record[i - 1][j] && (s1[i - 1] == s3[i + j - 1]))
					|| (record[i][j - 1] && (s2[j - 1] == s3[i + j - 1]));
			}
		}

		//for (auto&& x : record) {
		//	for (auto&& y : x) {
		//		cout << y << " ";
		//	}
		//	cout << endl;
		//}

		return record[len1][len2];
	}
#else
	bool isInterleave(string s1, string s2, string s3) {
		int len_s1 = s1.size();
		int len_s2 = s2.size();
		int len_s3 = s3.size();

		if (len_s1 + len_s2 != len_s3)
			return false;

		vector<vector<bool>> vec(len_s1 + 1, vector<bool>(len_s2 + 1, false));
		vec[0][0] = true;
		for (int i = 1; i != len_s1 + 1; i++) {
			vec[i][0] = vec[i - 1][0] && s1[i - 1] == s3[i - 1];
		}

		for (int i = 1; i != len_s2 + 1; i++) {
			vec[0][i] = vec[0][i - 1] && s2[i - 1] == s3[i - 1];
		}

		for (int i = 1; i != len_s1 + 1; i++) {
			for (int j = 1; j != len_s2 + 1; j++) {
				vec[i][j] = vec[i - 1][j] && s1[i - 1] == s3[i + j - 1]
					|| vec[i][j - 1] && s2[j - 1] == s3[i + j - 1];
			}
		}

		return vec[len_s1][len_s2];
	}
#endif
};


int main() {
	Solution sln;
	string s1;
	string s2;
	string s3;
	bool result;

	s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac";
	result = sln.isInterleave(s1, s2, s3);
	cout << result << endl;

	s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc";
	result = sln.isInterleave(s1, s2, s3);
	cout << result << endl;
}