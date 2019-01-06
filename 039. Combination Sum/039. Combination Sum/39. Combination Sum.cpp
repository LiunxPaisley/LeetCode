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
	void findSum(vector<int>& candidates, int target, vector<int>& temp, unordered_set<vector<int>>& result) {
		int can_size = candidates.size();
		for (int i = 0; i < can_size; ++i) {
			vector<int> vec = temp;
			int next = target - candidates[i];
			if (next > 0) {
				vec.push_back(candidates[i]);
				findSum(candidates, next, vec, result);
			} else if(next == 0){
				temp.push_back(candidates[i]);
				result.insert(temp);
				return;
			} else {
				return;
			}
			
		}
	}
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		unordered_set<vector<int>> result;
		vector<int> temp;
		findSum(candidates, target, temp, result);
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


	candidates = { 2,3,5 };
	target = 8;
	result = sln.combinationSum(candidates, target);
	for (auto&& x : result) {
		for (auto&& y : x) {
			cout << y << " ";
		}
		cout << endl;
	}
}