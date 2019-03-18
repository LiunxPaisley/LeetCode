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
	int largestRectangleArea(vector<int>& heights) {
		int height = 0;
		int width = 0;
		int max = 0;
		vector<int> largest(heights.size(), 0);
		for (int i = 0; i < heights.size(); ++i) {
			height = heights[i];
			if (i > 0 && heights[i] <= heights[i - 1]) {
				continue;
			}
			for (int j = i; j < heights.size(); ++j) {
				width = j - i + 1;
				if (height > heights[j]) {
					height = heights[j];
				}
				int area = width * height;
				if (largest[i] < area) {
					largest[i] = area;
				}
			}
			if (largest[i] > max) {
				max = largest[i];
			}
		}
		//for (auto&& x : largest) {
		//	cout << x << " ";
		//}
		//cout << "\n";
		return max;
	}
};


int main() {
	Solution sln;
	vector<int> heights;

	heights = { 2,1,5,6,2,3 };
	cout << sln.largestRectangleArea(heights) << endl;
}