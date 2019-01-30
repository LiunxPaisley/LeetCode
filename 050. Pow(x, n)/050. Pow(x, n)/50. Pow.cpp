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
	double myPow(double x, int n) {
		int pow_num = n < 0 ? -(n + 1) : n; // avoid case that n == INT_MIN
		double result = 1;
		double y = x;
		while (pow_num > 0) {
			if ((pow_num & 1) != 0) {
				result *= y;
			}
			y *= y;
			pow_num >>= 1;
			//cout << result << " " << pow_num << endl;;
		}
		return n < 0 ? (1 / result / x) : result;
	}
};


int main() {
	Solution sln;
	double x;
	int n;

	x = 2.00000, n = 10;
	cout << sln.myPow(x, n) << "\n\n";

	x = 2.10000, n = 3;
	cout << sln.myPow(x, n) << "\n\n";

	x = 2.00000, n = -2;
	cout << sln.myPow(x, n) << "\n\n";
}