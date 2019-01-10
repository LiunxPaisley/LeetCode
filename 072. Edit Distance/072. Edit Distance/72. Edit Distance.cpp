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
	int minDistance(string word1, string word2) {
		int len1 = word1.size();
		int len2 = word2.size();
		// padding
		distance = vector<vector<int>>(len1 + 1, vector<int>(len2 + 1, -1));
		return min_distance(word1, word2, len1 - 1, len2 - 1);
	}
private:
	vector<vector<int>> distance;
		
	int min_distance(const string& word1, const string& word2, int l1 , int l2) {
		if (!l1) return l2;
		if (!l2) return l1;
		if (distance[l1][l2] >= 0) return distance[l1][l2];
		
		int ans;
		if (word1[l1 - 1] == word2[l2 - 1]) {
			ans = min_distance(word1, word2, l1-1, l2-1);
		} else {
			ans = 1 + min(min_distance(word1, word2, l1-1,l2-1), // replace
						min(min_distance(word1, word2, l1 - 1, l2), // delete
							min_distance(word1, word2, l1, l2 - 1))); // insert
		}
		return distance[l1][l2] = ans;
	}
};


int main() {
	Solution sln;
	string word1;
	string word2;
	int result;

	word1 = "horse";
	word2 = "ros";
	result = sln.minDistance(word1, word2);
	cout << result << endl;

	word1 = "intention";
	word2 = "execution";
	result = sln.minDistance(word1, word2);
	cout << result << endl;
}