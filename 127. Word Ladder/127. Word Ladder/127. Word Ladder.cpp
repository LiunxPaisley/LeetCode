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
#include <cctype>

using namespace std;

class Solution {
public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		unordered_set<string> word_set(wordList.begin(), wordList.end());

		if (!word_set.count(endWord)) return 0;

		unordered_map<string, int> path_cnt{ {{beginWord, 1}} };
		queue<string> que;
		que.push(beginWord);
		while (!que.empty()) {
			string word = que.front();
			que.pop();
			for (int i = 0; i < word.size(); ++i) {
				for (char ch = 'a'; ch <= 'z'; ++ch) {
					string newword = word;
					newword[i] = ch;
					if (word_set.count(newword)) {
						if (newword == endWord) {
							return path_cnt[word] + 1;
						} else if (!path_cnt.count(newword)) {
							path_cnt[newword] = path_cnt[word] + 1;
							que.push(newword);
						}
					}
				}
			}
		}
		return 0;
	}
};


int main() {
	Solution sln;
	string beginWord;
	string endWord;
	vector<string> wordList;

	beginWord = "hit";
	endWord = "cog";
	wordList = { "hot","dot","dog","lot","log","cog" };
	cout << sln.ladderLength(beginWord, endWord, wordList) << endl;
}