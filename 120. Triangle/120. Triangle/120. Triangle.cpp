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
	int minimumTotal(vector<vector<int>>& triangle) {
		vector<int> vec(triangle[triangle.size() - 1].size(), 0);
		for (int i = 0; i < vec.size(); ++i) {
			vec[i] = min_path(triangle, triangle.size() - 1, i);
		}
		return *min_element(vec.begin(), vec.end());
	}
private:
	int min_path(vector<vector<int>>& triangle, int i, int j) {
		
		if (i == 0) {
			int min = 100000000;
			for (int k = j - 1; k < j + 2; ++k) {
				if (0 <= k && k < triangle[0].size()) {
					if (triangle[0][k] < min) {
						min = triangle[0][k];
					}
				}
			}
			return min;
		}
		vector<int> vec(triangle[i].size(), 0);
		for (int idx = 0; idx < triangle[i].size(); ++idx) {
			vec[idx] = triangle[i][idx] + min_path(triangle, i - 1, idx);
		}
		cout << "i = " << i << ", ";
		for (auto&& x : vec) {
			cout << x << " ";
		}
		cout << endl;
		return *min_element(vec.begin(), vec.end());
	}
};


int main() {
	Solution sln;
	vector<vector<int>> triangle;
	int result;

	triangle = { {2},
				{3,4},
				{6,5,7},
				{4,1,8,3} };
	result = sln.minimumTotal(triangle);
	cout << result << endl;
}