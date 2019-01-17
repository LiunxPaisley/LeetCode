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
	int maxProfit(vector<int>& prices) {
		if (prices.size() <= 1) {
			return 0;
		}
		vector<int> max_(prices.size()-1, 0);
		for (int i = 0; i < max_.size(); ++i) {
			max_[i] = max_profile(prices, 0, i + 2) + max_profile(prices, i + 2, prices.size());
		}

		for (auto&& x : max_) {
			cout << x << " ";
		}
		cout << endl;

		return *max_element(max_.begin(), max_.end());
	}
private:
	int max_profile(vector<int>& prices, int start, int end) {
		if (start >= end) {
			return 0;
		}
		vector<int> record(end - start, 0);
		for (int i = 0; i < record.size()-1; ++i) {
			for (int j = i+1; j < record.size(); ++j) {
				int profile = prices[start + j] - prices[start + i];
				if (profile > record[i]) {
					record[i] = profile;
				}
			}
		}

		cout << "start: " << start << ", end: " << end << ", ";
		for (auto&& x : record) {
			cout << x << " ";
		}
		cout << endl;
		
		return *max_element(record.begin(), record.end());
	}
};


int main() {
	Solution sln;
	vector<int> prices;
	int result;

	prices = { 3,3,5,0,0,3,1,4 };
	result = sln.maxProfit(prices);
	cout << result << endl;

	prices = { 1,2,3,4,5 };
	result = sln.maxProfit(prices);
	cout << result << endl;

	prices = { 7,6,4,3,1 };
	result = sln.maxProfit(prices);
	cout << result << endl;

	prices = { 2,1,2,0,1 };
	result = sln.maxProfit(prices);
	cout << result << endl;

}