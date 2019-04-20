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
	ListNode* sortList(ListNode* head) {
		if (!head || !(head->next)) return head;
		ListNode * fast = head;
		ListNode * slow = head;
		ListNode * pre = head;
		while (fast && fast->next) {
			pre = slow;
			slow = slow->next;
			fast = fast->next->next;
		}
		pre->next = NULL;
		ListNode* l1 = sortList(head);
		ListNode* l2 = sortList(slow);
		return merge(l1, l2);
	}
private:
	ListNode* merge(ListNode* l1, ListNode* l2) {
		ListNode* res = NULL;
		if (l1->val < l2->val) {
			res = l1;
			l1 = l1->next;
		} else {
			res = l2;
			l2 = l2->next;
		}
		ListNode* p = res;
		while (l1 && l2) {
			if (l1->val < l2->val) {
				p->next = l1;
				l1 = l1->next;
			} else {
				p->next = l2;
				l2 = l2->next;
			}
			p = p->next;
		}
		if (l1) {
			p->next = l1;
		}
		if (l2) {
			p->next = l2;
		}
		return res;
	}
};


int main() {
	Solution sln;
}