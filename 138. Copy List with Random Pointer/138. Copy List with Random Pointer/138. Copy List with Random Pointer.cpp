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

// Definition for a Node.
class Node {
public:
	int val;
	Node* next;
	Node* random;

	Node() {}

	Node(int _val, Node* _next, Node* _random) {
		val = _val;
		next = _next;
		random = _random;
	}
};

class Solution {
public:
	Node* copyRandomList(Node* head) {
		map<Node*, int> ht;
		map<int, Node*> copy_ht;
		Node* ptr = head;
		Node* res = NULL;
		Node** newnode = &res;
		int count = 0;
		while (ptr) {
			*newnode = new Node(ptr->val, NULL, NULL);
			ht[ptr] = count;
			copy_ht[count] = *newnode;
			count++;
			ptr = ptr->next;
			newnode = &((*newnode)->next);
		}
		ptr = head;
		Node* res_ptr = res;
		while (ptr) {
			if (!(ptr->random)) {
				res_ptr->random = NULL;
			} else {
				int idx = ht[ptr->random];
				res_ptr->random = copy_ht[idx];
			}
			ptr = ptr->next;
			res_ptr = res_ptr->next;
		}
		return res;
	}
};


int main() {
	Solution sln;
}