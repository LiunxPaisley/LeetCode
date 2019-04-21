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

/**
 * Runtime: 80 ms, faster than 93.44% of C++ online submissions for Implement Trie (Prefix Tree).
 * Memory Usage: 44.8 MB, less than 68.03% of C++ online submissions for Implement Trie (Prefix Tree).
 */
class Node {
public:
	Node() {
		memset(next, 0, sizeof(next));
		is_word = false;
	}
	Node* next[26];
	bool is_word;
};
class Trie {
public:
	/** Initialize your data structure here. */
	Trie() {
		root = new Node();
	}

	/** Inserts a word into the trie. */
	void insert(string word) {
		Node* p = root;
		for (int i = 0; i < word.size(); ++i) {
			if (p->next[word[i] - 'a'] == NULL) {
				p->next[word[i] - 'a'] = new Node();
			}
			p = p->next[word[i] - 'a'];
		}
		p->is_word = true;
	}

	/** Returns if the word is in the trie. */
	bool search(string word) {
		Node* p = root;
		for (int i = 0; i < word.size(); ++i) {
			if (p->next[word[i] - 'a'] == NULL) {
				return false;
			}
			p = p->next[word[i] - 'a'];
		}
		return p->is_word;
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix) {
		Node* p = root;
		for (int i = 0; i < prefix.size(); ++i) {
			if (p->next[prefix[i] - 'a'] == NULL) {
				return false;
			}
			p = p->next[prefix[i] - 'a'];
		}
		return true;
	}
private:
	Node* root;
};


int main() {

	// Your Trie object will be instantiated and called as such:
	string word = "apple";
	string prefix = "app";
	Trie* obj = new Trie();
	obj->insert(word);
	bool param_2 = obj->search(word);
	bool param_3 = obj->startsWith(prefix);

}