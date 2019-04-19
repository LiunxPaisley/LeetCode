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
 * Definition for singly-linked list.
 */
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* generate_list(vector<int>& nums) {
	ListNode* head;
	ListNode** ptr = &head;
	for (auto&& x : nums) {
		*ptr = new ListNode(x);
		ptr = &((*ptr)->next);
	}
	return head;
}

void print_list(ListNode* p) {
	while (p) {
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;
}

class Solution {
public:
	bool hasCycle(ListNode* head) {
		if (!head || !(head->next)) return false;
		ListNode * p1 = head;
		ListNode * p2 = head;
		while (p2->next && p2->next->next) {
			p1 = p1->next;
			p2 = p2->next->next;
			if (p1 == p2) return true;
		}
		return false;
	}
};


int main() {
	Solution sln;
}