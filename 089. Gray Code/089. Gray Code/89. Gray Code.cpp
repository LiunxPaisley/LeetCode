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

/*
000
001
011
010
110
100
101
111
*/
/*
0000 0
0001 1

0011 3
0010 2

0110 6
0111 7
0101 5
0100 4

1100 12
1101 
1111
1110

*/

class Solution {
public:
	vector<int> grayCode(int n) {
		//if (!n) return { 0 };
		//if (n == 1) return { 0, 1 };
		//vector<int> basic{0,1,3,2};
		vector<int> result{0};
		result.reserve(pow(2, n));
		int inc = 1;
		for (int i = 0; i < n; ++i) {
			int size = result.size();
			for (int j = size - 1; j >= 0; --j) {
				result.push_back(result[j] + inc);
			}
			inc = inc << 1;
		}
		return result;
	}
};


int main() {
	Solution sln;
	int n = 0;
	vector<int> result;

	n = 2;
	result = sln.grayCode(n);
	for (auto&& x : result) {
		cout << x << " ";
	}
	cout << endl;


	n = 3;
	result = sln.grayCode(n);
	for (auto&& x : result) {
		cout << x << " ";
	}
	cout << endl;

	n = 4;
	result = sln.grayCode(n);
	for (auto&& x : result) {
		cout << x << " ";
	}
	cout << endl;
}