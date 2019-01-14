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
}