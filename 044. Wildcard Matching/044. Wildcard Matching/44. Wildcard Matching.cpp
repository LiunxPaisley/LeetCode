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
	bool isMatch(string s, string p) {
		int len_s = s.size();
		int len_p = p.size();
		int i = 0, j = 0;
		while (i < len_s && j < len_p) {
			if (p[j] == '?') {
				++i;
				++j;
			} else if (p[j] == '*') {
				int k = i;
				while (s[k] != p[j + 1]) {
					++k;
				}
				
			} else {
				if (s[i] != p[j]) {
					return false;
				} else {
					++i;
					++j;
				}
			}
		}
		if (i == len_s && j == len_p) {
			return true;
		} else {
			return false;
		}
	}
};


int main() {
	Solution sln;
}