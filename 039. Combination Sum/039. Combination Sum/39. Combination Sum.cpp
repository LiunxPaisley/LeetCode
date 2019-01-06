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
	void findSum(vector<int>& candidates, int target, vector<int>& temp, set<vector<int>>& result, int idx) {
		int can_size = candidates.size();
		for (int i = idx; i < can_size; ++i) {
			vector<int>& vec = temp;
			int size = vec.size();
			int next = target - candidates[i];
			if (next > 0) {
				vec.push_back(candidates[i]);
				findSum(candidates, next, vec, result, i);
			} else if(next == 0){
				vec.push_back(candidates[i]);
				result.insert(vec);
				return;
			}
			vec.resize(size);
		}
	}
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		if (candidates.size() == 0) {
			return {};
		}
		sort(candidates.begin(), candidates.end());
		set<vector<int>> result;
		vector<int> temp;
		findSum(candidates, target, temp, result, 0);
		return vector<vector<int>>(result.begin(), result.end());
	}
};


int main() {
	Solution sln;
	vector<int> candidates;
	int target;
	vector<vector<int>> result;

	candidates = { 2,3,6,7 };
	target = 7;
	result = sln.combinationSum(candidates, target);
	for (auto&& x : result) {
		for (auto&& y : x) {
			cout << y << " ";
		}
		cout << endl;
	}
	cout << endl;

	candidates = { 2,3,5 };
	target = 8;
	result = sln.combinationSum(candidates, target);
	for (auto&& x : result) {
		for (auto&& y : x) {
			cout << y << " ";
		}
		cout << endl;
	}
	cout << endl;

	candidates = { 8,7,4,3 };
	target = 11;
	result = sln.combinationSum(candidates, target);
	for (auto&& x : result) {
		for (auto&& y : x) {
			cout << y << " ";
		}
		cout << endl;
	}
	cout << endl;

	candidates = { 4, 2, 8 };
	target = 8;
	result = sln.combinationSum(candidates, target);
	for (auto&& x : result) {
		for (auto&& y : x) {
			cout << y << " ";
		}
		cout << endl;
	}
	cout << endl;
}