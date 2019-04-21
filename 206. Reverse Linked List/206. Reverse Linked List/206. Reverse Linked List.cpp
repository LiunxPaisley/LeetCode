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
	/**
	 * Runtime: 8 ms, faster than 100.00% of C++ online submissions for Reverse Linked List.
     * Memory Usage: 9.1 MB, less than 78.69% of C++ online submissions for Reverse Linked List.
	 */
	ListNode* reverseList(ListNode* head) {
		if (!head || !(head->next)) return head;
		//ListNode* first = head;
		ListNode * p = head;
		while (p->next) {
			ListNode* tmp = p->next;
			p->next = tmp->next;
			tmp->next = head;
			head = tmp;
		}
		return head;
	}
};


int main() {
	Solution sln;
}