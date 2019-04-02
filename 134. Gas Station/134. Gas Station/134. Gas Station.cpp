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
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int tank = 0;
		//int cur_cost = 0;
		int cur = 0;
		int index = -1;
		bool flag = false;
		for (int i = 0; i < gas.size(); ++i) {
			if (gas[i] < cost[i]) {
				continue;
			}
			index = i;
			tank = gas[i] - cost[i];
			// cur_cost = cost[i];
			cur = (i + 1) % gas.size();

			while (cur != index) {
				tank += gas[cur];
				tank -= cost[cur];
				if (tank < 0) {
					flag = true;
					break;
				}
				cur++;
				cur = cur % gas.size();
			}
			if (flag) {
				flag = false;
				index = -1;
			} else {
				break;
			}
		}
		return index;
	}
};


int main() {
	Solution sln;
	vector<int> gas;
	vector<int> cost;

	gas = { 1,2,3,4,5 };
	cost = { 3,4,5,1,2 };
	cout << sln.canCompleteCircuit(gas, cost) << endl;

	gas = { 2,3,4 };
	cost = { 3,4,3 };
	cout << sln.canCompleteCircuit(gas, cost) << endl;
}