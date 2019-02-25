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

/**
 * Definition for an interval.
 */
struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
	vector<Interval> merge(vector<Interval>& intervals) {
		if (intervals.empty()) return {};
		sort(intervals.begin(), intervals.end(), [](Interval &a, Interval &b) {return a.start < b.start; });
		vector<Interval> res{ intervals[0] };
		for (int i = 1; i < intervals.size(); ++i) {
			if (res.back().end < intervals[i].start) {
				res.push_back(intervals[i]);
			} else {
				res.back().end = max(res.back().end, intervals[i].end);
			}
		}
		return res;
	}
};


int main() {
	Solution sln;
	vector<Interval> intervals;
	vector<Interval> result;

	intervals = { {1,3}, {2,6}, {8,10}, {15,18} };
	result = sln.merge(intervals);
	for (auto&& x : result) {
		cout << x.start << " " << x.end << "\n";
	}
	cout << "\n";

	intervals = { {1,4}, {4,5} };
	result = sln.merge(intervals);
	for (auto&& x : result) {
		cout << x.start << " " << x.end << "\n";
	}
	cout << "\n";

	intervals = { {1,100}, {20,80}, {30,50} };
	result = sln.merge(intervals);
	for (auto&& x : result) {
		cout << x.start << " " << x.end << "\n";
	}
	cout << "\n";

	intervals = { {20,80}, {1,100}, {30,50} };
	result = sln.merge(intervals);
	for (auto&& x : result) {
		cout << x.start << " " << x.end << "\n";
	}
	cout << "\n";

	intervals = { {10,40}, {30,70}, {60,80} };
	result = sln.merge(intervals);
	for (auto&& x : result) {
		cout << x.start << " " << x.end << "\n";
	}
	cout << "\n";

	intervals = { {2, 3},{4, 5},{6, 7},{8, 9},{1, 10} };
	result = sln.merge(intervals);
	for (auto&& x : result) {
		cout << x.start << " " << x.end << "\n";
	}
	cout << "\n";
}