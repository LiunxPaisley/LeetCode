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
	string simplifyPath(string path) {
		if (path.empty()) return "";
		if (path == "/") return path;
		string result;
		//result.reserve(path.size());
		deque<string> dq;
		int offset = 0;
		while (offset < path.size()) {
			int cur = path.find('/', offset + 1);
			string str = path.substr(offset + 1, cur - offset - 1);
			//cout << "str = " << str << endl;
			if (!str.empty()) {
				if (str == ".." && !dq.empty()) {
					dq.pop_back();
				} else if(str!= ".." && str != "."){
					dq.push_back(str);
				}
			}
			offset = cur;
		}
		while (!dq.empty()) {
			result += "/";
			result += dq.front();
			dq.pop_front();
		}
		if (result.empty()) {
			return "/";
		}
		//cout << "result = " << result << endl;;
		return result;
	}
};


int main() {
	Solution sln;
	string path;
	string result;

	path = "/home/";
	result = sln.simplifyPath(path);
	cout << result << "\n\n";

	path = "/../";
	result = sln.simplifyPath(path);
	cout << result << "\n\n";

	path = "/home//foo/";
	result = sln.simplifyPath(path);
	cout << result << "\n\n";

	path = "/a/./b/../../c/";
	result = sln.simplifyPath(path);
	cout << result << "\n\n";

	path = "/a/../../b/../c//.//";
	result = sln.simplifyPath(path);
	cout << result << "\n\n";

	path = "/a//b////c/d//././/..";
	result = sln.simplifyPath(path);
	cout << result << "\n\n";
}