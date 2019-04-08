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

class Node {
public:
	Node() {
		memset(next, 0, sizeof(next));
		is_word = false;
	}
	~Node() {
		for (int i = 0; i < 26; ++i) {
			if (next[i]) {
				delete next[i];
			}
		}
	}
	Node* next[26];
	bool is_word;
};

class WordDictionary {
public:
	/** Initialize your data structure here. */
	WordDictionary() {
		root = new Node();
	}
	~WordDictionary() {
		delete root;
	}
	/** Adds a word into the data structure. */
	void addWord(string word) {
		Node* p = root;
		for (int i = 0; i < word.size(); ++i) {
			if (!(p->next[word[i] - 'a'])) {
				p->next[word[i] - 'a'] = new Node();
			}
			p = p->next[word[i] - 'a'];
		}
		p->is_word = true;
	}

	/** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
	bool search(string word) {
		return _search(word, 0, root);
	}
private:
	bool _search(const string& word, int idx, Node* root) {
		Node* p = root;
		for (int i = idx; i < word.size() && p; ++i) {
			if (word[i] == '.') {
				for (int j = 0; j < 26; ++j) {
					if (p->next[j]) {
						if (_search(word, i + 1, p->next[j])) {
							return true;
						}
					}
				}
				return false;
			} else {
				p = p->next[word[i] - 'a'];
			}
		}
		return p && p->is_word;
	}
private:
	Node* root;
};


int main() {
	string word;
	WordDictionary* obj = new WordDictionary();

	word = "whatisthis";
	obj->addWord(word);
	cout << word << ": " << obj->search(word) << endl;

	word = "whatisthat";
	obj->addWord(word);
	cout << word << ": " << obj->search(word) << endl;

	word = "whatisthit";
	cout << word << ": " << obj->search(word) << endl;

	word = "";
	obj->addWord(word);
	word = "bad";
	obj->addWord(word);
	word = "dad";
	obj->addWord(word);
	word = "mad";
	obj->addWord(word);
	word = "pad";
	obj->addWord(word);
	word = "bad";
	cout << word << ": " << obj->search(word) << endl;
	word = ".ad";
	cout << word << ": " << obj->search(word) << endl;
	word = "b..";
	cout << word << ": " << obj->search(word) << endl;
	word = "b.d";
	cout << word << ": " << obj->search(word) << endl;
	word = "b.p";
	cout << word << ": " << obj->search(word) << endl;
	word = "..p";
	cout << word << ": " << obj->search(word) << endl;
	word = "b.p";
	cout << word << ": " << obj->search(word) << endl;
	word = "p.";
	cout << word << ": " << obj->search(word) << endl;

	word = "a";
	obj->addWord(word);
	word = ".";
	cout << word << ": " << obj->search(word) << endl;
	word = "a";
	cout << word << ": " << obj->search(word) << endl;
	word = "aa";
	cout << word << ": " << obj->search(word) << endl;
	word = ".a";
	cout << word << ": " << obj->search(word) << endl;
	word = "a.";
	cout << word << ": " << obj->search(word) << endl;
}