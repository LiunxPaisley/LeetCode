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
	string getPermutation(int n, int k) {
		string result(n, ' ');
		for (int i = 0; i < n; ++i) {
			result[i] = i + 1 + '0';
		}
		for (int j = 0; j < k - 1; ++j) {
			next_permutation(result.begin(), result.end());
		}
		return result;
	}
};


int main() {
	Solution sln;
	int n = 0, k = 0;
	
	n = 3;
	k = 3;
	cout << sln.getPermutation(n, k) << "\n";

	n = 4;
	k = 9;
	cout << sln.getPermutation(n, k) << "\n";
}