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
	vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
		//if (intervals.empty()) return {};
		intervals.push_back(newInterval);
		sort(intervals.begin(), intervals.end(), [](Interval& a, Interval& b) { return a.start < b.start; });
		vector<Interval> result{intervals[0]};
		for (int i = 1; i < intervals.size(); ++i) {
			if (result.back().end < intervals[i].start) {
				result.push_back(intervals[i]);
			} else {
				result.back().end = max(result.back().end, intervals[i].end);
			}
		}
		return result;
	}
};


int main() {
	Solution sln;
	vector<Interval> intervals;
	Interval newInterval;
	vector<Interval> result;

	intervals = { {1,3 }, { 6,9 } };
	newInterval = {2,5};
	result = sln.insert(intervals, newInterval);
	for (auto&& x : result) {
		cout << x.start << " " << x.end << "\n";
	}
	cout << "\n";

	intervals = {  };
	newInterval = { 5,7 };
	result = sln.insert(intervals, newInterval);
	for (auto&& x : result) {
		cout << x.start << " " << x.end << "\n";
	}
	cout << "\n";
}