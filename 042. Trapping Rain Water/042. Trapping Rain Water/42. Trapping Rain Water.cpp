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
	int trap(vector<int>& height) {
		int result = 0;

		int height_size = height.size();
		for (int i = 0; i < height_size;) {
			// find bigger one
			int flag = false;
			int j;
			for (j = i+1; j < height_size; ++j) {
				if (height[j] >= height[i]) {
					result += (j - i - 1)*height[i];
					//i = j;
					flag = true;
					break;
				}
			}
			//cout << "result = " << result << endl;
			//cout << "i = " << i << endl;
			// find max one
			if (!flag) {
				vector<int>::iterator iter = max_element(height.begin()+(i+1), height.end());
				if (iter == height.end()) {
					break;
				}
				j = iter - height.begin();
				//cout << "j = " << j << endl;
				result += (j - i - 1)*height[j];
			}
			// minus the block
			while (++i != j) {
				result -= height[i];
			}
		}
		return result;
	}
};


int main() {
	Solution sln;
	vector<int> height;
	//int result;

	height = { 0,1,0,2,1,0,1,3,2,1,2,1 };
	cout << sln.trap(height) << endl;
}