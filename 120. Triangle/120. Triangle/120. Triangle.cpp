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
	/* solution 1 */
	int minimumTotal(vector<vector<int>>& triangle) {
		vector<vector<int>> record(triangle.size(), vector<int>());
		for (int i = 0; i < record.size(); ++i) {
			record[i].resize(triangle[i].size());
		}
		record[0][0] = triangle[0][0];
		/*min_path(triangle, record, )*/
		for (int r = 1; r < record.size(); ++r) {
			for (int c = 0; c < record[r].size(); ++c) {
				//if (record[r][c] < 0) {
				if (c == 0) {
					record[r][c] = triangle[r][c] + record[r - 1][c];
				} else if (c == record[r - 1].size()) {
					record[r][c] = triangle[r][c] + record[r - 1][c - 1];
				} else {
					record[r][c] = min(triangle[r][c] + record[r-1][c - 1], triangle[r][c] + record[r-1][c]);
				}
				
				//}
			}
		}
		//for (auto&& x : record) {
		//	for (auto&& y : x) {
		//		cout << y << " ";
		//	}
		//	cout << endl;
		//}
		//cout << endl;
		return *min_element(record[record.size()-1].begin(), record[record.size() - 1].end());
	}
private:
	//int min_path(int last, vector<vector<int>>& record, int r, int c) {
	//	int min = 2000000000;
	//	//int k = 0;
	//	int r_size = record[r].size();
	//	for (int i = c; i <= c + 1 && i < r_size; ++i) {
	//			int res = last + record[r][i]);
	//			if (res < min) {
	//				min = res;
	//				//k = i;
	//			}
	//		cout << "r = " << r << ", c = " << c << ", i = " << i  << ", min= " << min << endl;
	//	}
	//	return last + record[r][k];
	//}
};


int main() {
	Solution sln;
	vector<vector<int>> triangle;
	int result;

	triangle = { {2},
				{3,4},
				{6,5,7},
				{4,1,8,3} };
	result = sln.minimumTotal(triangle);
	cout << result << endl << endl;

	triangle = { {-1}, { 3, 2 }, { -3, 1, -1 } };
	result = sln.minimumTotal(triangle);
	cout << result << endl << endl;

	triangle = { {-1}, { 3, 2 }, { 1, -2, -1 } };
	result = sln.minimumTotal(triangle);
	cout << result << endl << endl;
}