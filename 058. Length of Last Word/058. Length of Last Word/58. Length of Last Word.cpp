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
	int lengthOfLastWord(string s) {
		if (s.empty()) return 0;
		int count = 0;
		for (int i = s.size() - 1; i >= 0; --i) {
			if (s[i] != ' ') {
				while (i >= 0 && s[i] != ' ') {
					++count;
					--i;
				}
				return count;
			}
		}
		return count;
	}
};


int main() {
	Solution sln;
	string s;
	
	s = "Hello World";
	cout << sln.lengthOfLastWord(s) << endl;

	s = "Hello World ";
	cout << sln.lengthOfLastWord(s) << endl;

	s = "     ";
	cout << sln.lengthOfLastWord(s) << endl;

	s = "a";
	cout << sln.lengthOfLastWord(s) << endl;
}