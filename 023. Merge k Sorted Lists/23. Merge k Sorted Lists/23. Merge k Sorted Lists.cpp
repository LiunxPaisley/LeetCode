#include <iostream>
#include <vector>
#include <string>
#include <limits.h>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
	int       val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		int list_size = lists.size();
		vector<ListNode*> ptrs(list_size, nullptr);
		for (int i = 0; i < list_size; ++i) {
			ptrs[i] = lists[i];
		}

		int exit;
		
		ListNode* result = nullptr;
		ListNode** p = &result;
		while (true) {
			exit = 1;
			for (ListNode* x : ptrs) {
				if (x) {
					exit = 0;
					break;
				}
			}
			if (exit) {
				break;
			} else {
				int min_val = INT_MAX;
				int idx;
				for (int i = 0; i < list_size; ++i) {
					if (ptrs[i] && ptrs[i]->val < min_val) {
						min_val = ptrs[i]->val;
						idx = i;
					}	
				}
				//cout << min_val << " " << idx << endl;
				*p = new ListNode(min_val);
				p = &((*p)->next);
				ptrs[idx] = ptrs[idx]->next;
			}
		}
		return result;
	}
};

int main() {
	Solution sln;

	vector<ListNode*> lists(3);
	
	ListNode** p0 = &lists[0];
	for (int i = 0; i < 15; ++i) {
		*p0 = new ListNode(2 * i);
		p0 = &((*p0)->next);
	}

	ListNode* iter0 = lists[0];
	while (iter0) {
		cout << iter0->val << " ";
		iter0 = iter0->next;
	}
	cout << endl;

	ListNode** p1 = &lists[1];
	for (int i = 0; i < 10; ++i) {
		*p1 = new ListNode(3 * i - 2);
		p1 = &((*p1)->next);
	}
	

	ListNode* iter1 = lists[1];
	while (iter1) {
		cout << iter1->val << " ";
		iter1 = iter1->next;
	}
	cout << endl;

	ListNode** p2 = &lists[2];
	for (int i = 0; i < 20; ++i) {
		*p2 = new ListNode(4 * i - 5);
		p2 = &((*p2)->next);
	}

	ListNode* iter2 = lists[2];
	while (iter2) {
		cout << iter2->val << " ";
		iter2 = iter2->next;
	}
	cout << endl;

	ListNode* result = sln.mergeKLists(lists);
	ListNode* iter3 = result;
	while (iter3) {
		cout << iter3->val << " ";
		iter3 = iter3->next;
	}
	cout << endl;
}