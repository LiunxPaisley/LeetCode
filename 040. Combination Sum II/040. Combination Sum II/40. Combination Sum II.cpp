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
	void findSum(vector<int>& candidates, int target, vector<int>& temp, vector<vector<int>>& result, int idx) {
		int can_size = candidates.size();
		for (int i = idx; i < can_size; ++i) {
			vector<int>& vec = temp;
			int size = vec.size();
			int next = target - candidates[i];
			if (next > 0) {
				vec.push_back(candidates[i]);
				findSum(candidates, next, vec, result, i+1);
			} else if (next == 0) {
				vec.push_back(candidates[i]);
				result.push_back(vec);
				return;
			}
			// 回溯法，resize可以避免vector<int>& vec = temp;执行拷贝，大量减少执行时间
			vec.resize(size);
		}
	}
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		vector<vector<int>> result;
		vector<int> temp;
		findSum(candidates, target, temp, result, 0);
		// remove multiple element
		set<vector<int>> s(result.begin(), result.end());
		return vector<vector<int>>(s.begin(), s.end());
	}
};


int main() {
	Solution sln;
	vector<int> candidates;
	int target;
	vector<vector<int>> result;

	candidates = { 10,1,2,7,6,1,5 };
	target = 8;
	result = sln.combinationSum2(candidates, target);
	for (auto&& x : result) {
		for (auto&& y : x) {
			cout << y << " ";
		}
		cout << endl;
	}
	cout << endl;

	candidates = { 2,5,2,1,2 };
	target = 5;
	result = sln.combinationSum2(candidates, target);
	for (auto&& x : result) {
		for (auto&& y : x) {
			cout << y << " ";
		}
		cout << endl;
	}
	cout << endl;
}