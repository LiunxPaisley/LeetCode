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
	string addBinary(string a, string b) {
		if (a.size() < b.size()) {
			std::swap(a, b);
		}
		int in = 0;
		for (int i = a.size() - 1, j = b.size() - 1; j >= 0; --i, --j) {
			int temp = (a[i] - '0') + (b[j] - '0') + in;
			a[i] = temp % 2 + '0';
			in = temp / 2;
		}
		for (int j = a.size() - b.size() - 1; j >= 0; j--) {
			int temp = (a[j] - '0') + in;
			a[j] = temp % 2 + '0';
			in = temp / 2;
		}
		if (in) {
			a = "1" + a;
		}
		return a;
	}
};


int main() {
	Solution sln;
	string a, b;

	a = "11", b = "1";
	cout << sln.addBinary(a, b) << "\n\n";

	a = "1010", b = "1011";
	cout << sln.addBinary(a, b) << "\n\n";

	a = "1010", b = "1011011101";
	cout << sln.addBinary(a, b) << "\n\n";

	a = "1111", b = "11111111111111";
	cout << sln.addBinary(a, b) << "\n\n";

}