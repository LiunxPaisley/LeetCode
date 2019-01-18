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
	string multiply(string num1, string num2) {
		string result(1000, '0');
		reverse(num1.begin(), num1.end());
		reverse(num2.begin(), num2.end());

		int ans = 0;
		for (int i = 0; i < num1.size(); ++i) {
			for (int j = 0; j < num2.size(); ++j) {
				ans = (num1[i] - '0')*(num2[j] - '0') + (result[i + j] - '0');
				result[i + j + 1] = (result[i + j + 1] - '0') + ans / 10 + '0';
				result[i + j] = ans % 10 + '0';
			}
		}
		
		reverse(result.begin(), result.end());

		size_t pos = result.find_first_not_of('0');
		
		if (pos == string::npos) {
			return "0";
		} else {
			return result.substr(pos);
		}		
	}
};


int main() {
	Solution sln;
	string num1;
	string num2;

	num1 = "2", num2 = "3";
	cout << num1 << " x " << num2 << " = " << sln.multiply(num1, num2) << endl;

	num1 = "123", num2 = "456";
	cout << num1 << " x " << num2 << " = " << sln.multiply(num1, num2) << endl;

	num1 = "123456789", num2 = "987654321";
	cout << num1 << " x " << num2 << " = " << sln.multiply(num1, num2) << endl;

	num1 = "0", num2 = "987654321";
	cout << num1 << " x " << num2 << " = " << sln.multiply(num1, num2) << endl;

	num1 = "10000", num2 = "10000000000";
	cout << num1 << " x " << num2 << " = " << sln.multiply(num1, num2) << endl;

	num1 = "4378954785437843", num2 = "987654321";
	cout << num1 << " x " << num2 << " = " << sln.multiply(num1, num2) << endl;
}