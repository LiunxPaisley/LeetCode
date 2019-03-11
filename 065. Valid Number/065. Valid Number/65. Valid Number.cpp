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

// [+-][float][e][+-][Integer]
class Solution {
public:
	bool isNumber(string s) {
		if (s.empty()) return false;
		auto first = s.begin();
		while (*first == ' ') {
			++first;
		}
		auto last = s.end();
		--last;
		while (*last == ' ') {
			--last;
		}
		++last;
		if (first >= last) return false;
		string str(first, last);
		
		cout << "str = " << str << "\n";

		string::iterator iter = str.begin();
		bool b1 = isFloating(iter, str);
		cout << "b1 = " << b1 << "\n";
		bool b2 = isInteger(iter, str);
		cout << "b2 = " << b2 << "\n";

		
		return b1 && b2;

	}
private:
	bool isFloating(string::iterator& iter, const string& s) {
		int sign = false;
		int point = false;
		int integer = false;
		if (*iter == '+' || *iter == '-') {
			/*if (sign == false) {
				sign = true;
				continue;
			} else {
				return false;
			}*/
			++iter;
		}
		if (*iter == 'e') {
			return false;
		}
		for (; iter != s.end() && *iter != 'e'; ++iter) {
			if (*iter < '0' || *iter > '9') {
				if (*iter == '.' && point == false) {
					point = true;
				} else {
					return false;
				}
			} else {
				integer = true;
			}
		}
		return true;
	}
	bool isInteger(string::iterator& iter, const string& s) {
		//int sign = false;
		if (iter == s.end()) {
			return true;
		}
		if (*iter == 'e') {
			++iter;
			if (iter == s.end()) {
				return false;
			}
		}
		if (*iter == '+' || *iter == '-') {
			++iter;
		}
		//cout << "ffdfdf\n";
		for (; iter != s.end(); ++iter) {
			if (*iter < '0' || *iter > '9') {
				return false;
			}
		}
		return true;
	}
};


int main() {
	Solution sln;
	string s;

	s = "";
	cout << (sln.isNumber(s) == false) << "\n\n";
	/*s = " ";
	cout << (sln.isNumber(s) == false) << "\n\n";*/
	s = "0";
	cout << (sln.isNumber(s) == true) << "\n\n";

	s = ".1";
	cout << (sln.isNumber(s) == true) << "\n\n";

	s = " 0.1 "; 
	cout << (sln.isNumber(s) == true) << "\n\n";

	s = "abc"; 
	cout << (sln.isNumber(s) == false) << "\n\n";

	s = "1 a"; 
	cout << (sln.isNumber(s) == false) << "\n\n";

	s = "2e10"; 
	cout << (sln.isNumber(s) == true) << "\n\n";

	s = " -90e3   "; 
	cout << (sln.isNumber(s) == true) << "\n\n";

	s = " 1e"; 
	cout << (sln.isNumber(s) == false) << "\n\n";

	s = "e3"; 
	cout << (sln.isNumber(s) == false) << "\n\n";

	s = " 6e-1"; 
	cout << (sln.isNumber(s) == true) << "\n\n";

	s = " 99e2.5 "; 
	cout << (sln.isNumber(s) == false) << "\n\n";

	s = "53.5e93"; 
	cout << (sln.isNumber(s) == true) << "\n\n";

	s = " --6 "; 
	cout << (sln.isNumber(s) == false) << "\n\n";

	s = "-+3"; 
	cout << (sln.isNumber(s) == false) << "\n\n";

	s = "95a54e53"; 
	cout << (sln.isNumber(s) == false) << "\n\n";

	s = "95.5.4e53";
	cout << (sln.isNumber(s) == false) << "\n\n";

	s = "95.54e5e3";
	cout << (sln.isNumber(s) == false) << "\n\n";
}