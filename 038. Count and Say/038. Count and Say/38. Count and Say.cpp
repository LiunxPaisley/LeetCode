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
	string countAndSay(int n) {
		string result{ "1" };
		if (n == 1) {
			return result;
		}
		/*string result;*/
		for (int i = 1; i < n; ++i) {
			int size = result.size();
			int k = 0;
			stringstream ss;
			
			while (k < size) {
				int count = 1;
				//printf("*** %d\n", result[k + 1]);
				while (result[k] == result[k + 1]) {
					
					count++;
					k++;
				}
				ss << count << result[k];
				k++;
			}
			result = ss.str();
			//cout << result << endl;
		}
		return result;
	}
};


int main() {
	Solution sln;
	int n;
	string result;

	n = 2;
	result = sln.countAndSay(n);
	cout << result << endl;

	n = 3;
	result = sln.countAndSay(n);
	cout << result << endl;

	n = 4;
	result = sln.countAndSay(n);
	cout << result << endl;

	n = 5;
	result = sln.countAndSay(n);
	cout << result << endl;

	n = 6;
	result = sln.countAndSay(n);
	cout << result << endl;
}