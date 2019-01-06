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
	bool isPalindrome(int x) {
		if (x < 0) {
			return false;
		}
		int total = 0;
		int rest = 0;
		int x0 = x;
		while (x != 0) {
			rest = x % 10;
			total = total * 10 + rest;
			x = x / 10;
		}
		if (total == x0) {
			return true;
		} else {
			return false;
		}
	}
};


int main() {
	Solution sln;
	int x;
	bool result;

	x = -121;
	result = sln.isPalindrome(x);
	cout << result << endl;

	x = 121;
	result = sln.isPalindrome(x);
	cout << result << endl;

	x = 10;
	result = sln.isPalindrome(x);
	cout << result << endl;

}