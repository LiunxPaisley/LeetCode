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
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int i = 0;
		int j = 0;
		nums1.resize(m);
		while (j < n) {
			if (i < m && nums1[i] < nums2[j]) {
				++i;
			} else {
				if (i < m) {
					nums1.insert(nums1.begin() + i, nums2[j]);
					++m;
				} else {
					nums1.push_back(nums2[j]);
				}
				++i;
				++j;
			}
		}
	}
};


int main() {
	Solution sln;
	vector<int> nums1;
	vector<int> nums2;
	int m = 0;
	int n = 0;

	nums1 = { 1,2,3,0,0,0,0,0 };
	nums2 = { 1,2,3,5,6 };
	m = 3;
	n = 5;
	sln.merge(nums1, m, nums2, n);
	for (auto&& x : nums1) {
		cout << x << " ";
	}
	cout << "\n";
}