#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
	int       val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode* p1 = l1;
		ListNode* p2 = l2;

		ListNode* result;
		ListNode** p = &result;

		while (p1 && p2) {
			if (p1->val < p2->val) {
				*p = new ListNode(p1->val);
				p1 = p1->next;
			} else {
				*p = new ListNode(p2->val);
				p2 = p2->next;
			}
			p = &((*p)->next);
		}


		while (p1) {
			*p = new ListNode(p1->val);
			p = &((*p)->next);
			p1 = p1->next;
		}
		while (p2) {
			*p = new ListNode(p2->val);
			p = &((*p)->next);
			p2 = p2->next;
		}

		return result;
	}
};

int main() {
	Solution sln;

	ListNode* l1 = new ListNode(1);
	ListNode* pl1 = l1;
	for (int i = 3; i <= 50; ++i) {
		if (i % 2 != 0) {
			ListNode* p = new ListNode(i);
			pl1->next = p;
			pl1 = pl1->next;
		}
	}

	ListNode* iter1 = l1;
	while (iter1) {
		cout << iter1->val << " ";
		iter1 = iter1->next;
	}
	cout << endl;

	ListNode* l2 = new ListNode(0);
	ListNode*     pl2 = l2;
	for (int i = 2; i <= 50; ++i) {
		if (i % 2 == 0) {
			ListNode* p = new ListNode(i);
			pl2->next = p;
			pl2 = pl2->next;
		}
	}

	ListNode* iter2 = l2;
	while (iter2) {
		cout << iter2->val << " ";
		iter2 = iter2->next;
	}
	cout << endl;

	ListNode* result = sln.mergeTwoLists(l1, l2);

	ListNode* p1 = result;
	while (p1) {
		cout << p1->val << " ";
		p1 = p1->next;
	}
}