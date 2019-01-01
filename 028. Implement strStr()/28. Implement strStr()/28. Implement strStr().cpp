
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
	void get_next(int* next, string& needle) {
		next[0] = -1;
		int k = -1;
		int j = 0;
		int string_size = needle.size();
		while(j < string_size - 1) {
			if (k == -1 || needle[k] == needle[j]) {
				++k;
				++j;
				next[j] = k;
			} else {
				k = next[k];
			}
		}
	}

	int strStr(string haystack, string needle) {
		if (needle.empty()) {
			return 0;
		}
		int next_size = needle.size();
		int* next = new int[next_size + 1];
		memset(next, 0, (next_size + 1) * sizeof(int));
		get_next(next, needle);

		cout << "next: ";
		for (int i = 0; i <= needle.size(); ++i) {
			cout << next[i] << " ";
		}
		cout << endl;

		int i = 0;
		int j = 0;
		int haystack_size = haystack.size();
		int needle_size = needle.size();
		while (i < haystack_size && j < needle_size) {
			if (j == -1 || haystack[i] == needle[j] ) {
				++i;
				++j;
			} else {
				j = next[j];
			}
		}
		if (j == needle_size) {
			return i - j;
		} else {
			return -1;
		}
	}
};


int main() {
	Solution sln;
	string haystack = "aabaaabaaac";
	string needle = "aabaaac";
	int result = sln.strStr(haystack, needle);
	cout << "result = " << result << endl;
}