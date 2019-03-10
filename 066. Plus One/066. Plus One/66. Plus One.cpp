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
	vector<int> plusOne(vector<int>& digits) {
		//result.reserve(digits.size() + 1);
		int in = 1;
		for (int i = digits.size() - 1; i >= 0; --i) {
			int temp = digits[i] + in;
			digits[i] = temp % 10;
			in = temp / 10;
		}
		if (in) {
			digits.insert(digits.begin(), in);
		}
		return digits;
	}
};


int main() {
	Solution sln;
	vector<int> digits;

	digits = {1,2,3};
	sln.plusOne(digits);
	for (auto&& x : digits) {
		cout << x;
	}
	cout << "\n";

	digits = { 4,3,2,1 };
	sln.plusOne(digits);
	for (auto&& x : digits) {
		cout << x;
	}
	cout << "\n";

	digits = { 9,9,9,9,9,9,9,9 };
	sln.plusOne(digits);
	for (auto&& x : digits) {
		cout << x;
	}
	cout << "\n";

}