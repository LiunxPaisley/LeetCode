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
	int jump(vector<int>& nums) {
		int nums_size = nums.size();
		//vector<vector<int>> dis(nums_size, vector<int>(nums_size, 0));
		vector<int> dis(nums_size, 10000000);
		dis[0] = 0;
		for (int i = 0; i < nums_size; ++i) {
			int range = nums[i];
			for (int j = 1; j <= range; ++j) {
				if (i + j < nums_size) {
					dis[i + j] = (dis[i + j] > dis[i] + 1) ? dis[i] + 1 : dis[i + j];
				}
			}
		}

		//for (auto&& x : dis) {
		//	cout << x << " ";
		//}
		//cout << endl;

		return dis.back();
	}
};


int main() {
	Solution sln;
	vector<int> nums;

	nums = { 2,3,1,1,4 };
	cout << sln.jump(nums) << "\n\n";

	nums = { 2,3,0,1,4 };
	cout << sln.jump(nums) << "\n\n";

	nums = { 0 };
	cout << sln.jump(nums) << "\n\n";


	nums = {5, 6, 4, 4, 6, 9, 4, 4, 7, 4, 4, 8, 2, 6, 8, 1, 5, 9, 6, 5, 2, 7, 9, 7, 9, 6, 9, 4, 1, 6, 8, 8, 4, 4, 2, 0, 3, 8, 5};
	cout << sln.jump(nums) << "\n\n";
}