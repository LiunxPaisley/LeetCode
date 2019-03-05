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
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> result(n, vector<int>(n, 0));
		int count = 1;
		int max = n * n;
		enum direction { RIGHT, DOWN, LEFT, UP};
		direction cur = RIGHT;
		int i = 0, j = 0;
		int left = 0, right = n - 1, up = 0, down = n - 1;

		while (count <= max) {
			result[i][j] = count;
			
			switch (cur) {
			case RIGHT:
				if (j == right) {
					++up;
					++i;
					cur = DOWN;
				} else {
					++j;
				}
				break;
			case DOWN:
				if (i == down) {
					--right;
					--j;
					cur = LEFT;
				} else {
					++i;
				}
				break;
			case LEFT:
				if (j == left) {
					--down;
					--i;
					cur = UP;
				} else {
					--j;
				}
				break;
			case UP:
				if (i == up) {
					++left;
					++j;
					cur = RIGHT;
				} else {
					--i;
				}
				break;
			default:
				break;
			}
			++count;
			//cout << "i = " << i << ", j = " << j << "\n";
		}
		return result;
	}
};


int main() {
	Solution sln;
	int n;
	vector<vector<int>> result;

	n = 3;
	result = sln.generateMatrix(n);
	for (auto&& x : result) {
		for (auto&& y : x) {
			cout << y << " ";
		}
		cout << "\n";
	}
	cout << "\n";

	n = 5;
	result = sln.generateMatrix(n);
	for (auto&& x : result) {
		for (auto&& y : x) {
			cout << y << " ";
		}
		cout << "\n";
	}
	cout << "\n";

	n = 8;
	result = sln.generateMatrix(n);
	for (auto&& x : result) {
		for (auto&& y : x) {
			cout << y << " ";
		}
		cout << "\n";
	}
	cout << "\n";

	n = 10;
	result = sln.generateMatrix(n);
	for (auto&& x : result) {
		for (auto&& y : x) {
			cout << y << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}