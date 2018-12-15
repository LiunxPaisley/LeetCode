#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	void func(vector<string>& vec, string s, int left, int right, int wait) {
		if (left == 0 && right == 0 && wait == 0) {
			//cout << "s = " << s << endl;
			vec.push_back(s);
			return;
		}
		if (!left) {
			func(vec, s + ")", left, right - 1, wait - 1);
		} else {
			func(vec, s + "(", left - 1, right, wait + 1);
			if (wait > 0) {
				func(vec, s + ")", left, right - 1, wait - 1);
			}
		}
	}
	vector<string> generateParenthesis(int n) {
		vector<string> result;
		func(result, string("("), n - 1, n, 1);
		return result;
	}
};

int main() {
	Solution sln;
	int n = 5;
	vector<string> result = sln.generateParenthesis(n);
	for (auto&& item : result) {
		cout << item << endl;
	}
}