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
	// Newton-Raphson method
	int mySqrt(int x) {
		if (x <= 1) return x;
		long res = x >> 1;
		while (res * res > x) {
			res = (res + x / res) / 2;
		}
		return res;
	}
};


int main() {
	Solution sln;
	int n;

	for (n = 1; n <= 100; ++n) {
		cout << "sqrt(" << n << ") = " << sln.mySqrt(n) << "\n";
	}
	cout << "\n";

	n = 1000;
	cout << "sqrt(" << n << ") = " << sln.mySqrt(n) << endl;
}