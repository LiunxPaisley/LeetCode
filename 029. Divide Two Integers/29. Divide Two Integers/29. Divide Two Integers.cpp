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
	int divide(int dividend, int divisor) {
		if (divisor == 0) {
			return INT_MAX;
		}
		if (dividend == INT_MIN && divisor == -1) {
			return INT_MAX;
		}
		int sign = 0;
		int result = 0;
		// this statement is much efficient than if(...){...}
		sign = (dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0);
		long a = abs((long)dividend);
		long b = abs((long)divisor);
		int count = 0;
		// a = b * result + c;
		// result = 2^shift1 + 2^shift2 + ...
		while (a >= b) {

			// count++;
			// c = c - b;
			int shift = 0;
			while (a >= (b << shift)) {
				shift++;
			}
			shift--;
			a -= b << shift;
			result += 1 << shift;
		}

		return sign ? -result : result;
	}
};


int main() {
	Solution sln;
	int dividend = -2147483648;
	int divisor = -1;
	int result = sln.divide(dividend, divisor);
	cout << result << endl;
	cout << dividend / divisor << endl;
}