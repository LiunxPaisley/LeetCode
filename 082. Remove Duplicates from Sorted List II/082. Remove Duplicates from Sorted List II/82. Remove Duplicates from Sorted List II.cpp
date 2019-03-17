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

/**
 * Definition for singly-linked list.
 */
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == NULL) return head;
		if (head->next == NULL) return head;
		if (head->next->next == NULL) {
			if (head->next->val == head->val) {
				return NULL;
			} else {
				return head;
			}
		}
		ListNode** cur = &(head->next);
		ListNode** prev = &head;
		//ListNode** prevprev = prev;
		while (*cur != NULL) {
			if ((*cur)->val != (*prev)->val) {
				//prevprev = prev;
				prev = cur;
				cur = &((*cur)->next);
			} else {
				while (*cur != NULL && (*cur)->val == (*prev)->val) {
					cur = &((*cur)->next);
				}
				//if (*prev == head) {
				//	*prevprev = *cur;
				//} else {
				//	(*prevprev)->next = *cur;
				//}
				//prevprev = cur;
				//prev = &((*prevprev)->next);
				//cur = &((*prev)->next);
				*prev = *cur;
				//prev = cur;
				if (*cur != NULL) {
					cur = &((*cur)->next);
				}
			}
		}
		return head;
	}
};


int main() {
	Solution sln;

	vector<int> nums;
	ListNode* head;
	ListNode* result;
	ListNode** ptr;

	nums = { 1,2,3,3,4,4,5 };
	ptr = &head;
	for (auto&& x : nums) {
		*ptr = new ListNode(x);
		ptr = &((*ptr)->next);
	}
	//ListNode* p = head;
	//while (p != NULL) {
	//	cout << p->val << " ";
	//	p = p->next;
	//}
	//cout << endl;
	result = sln.deleteDuplicates(head);
	cout << "result = ";
	while (result != NULL) {
		cout << result->val << " ";
		result = result->next;
	}
	cout << endl;


	nums = { 1 };
	ptr = &head;
	for (auto&& x : nums) {
		*ptr = new ListNode(x);
		ptr = &((*ptr)->next);
	}
	result = sln.deleteDuplicates(head);
	cout << "result = ";
	while (result != NULL) {
		cout << result->val << " ";
		result = result->next;
	}
	cout << endl;

	nums = { 1, 1 };
	ptr = &head;
	for (auto&& x : nums) {
		*ptr = new ListNode(x);
		ptr = &((*ptr)->next);
	}
	result = sln.deleteDuplicates(head);
	cout << "result = ";
	while (result != NULL) {
		cout << result->val << " ";
		result = result->next;
	}
	cout << endl;

	nums = { 1, 2 };
	ptr = &head;
	for (auto&& x : nums) {
		*ptr = new ListNode(x);
		ptr = &((*ptr)->next);
	}
	result = sln.deleteDuplicates(head);
	cout << "result = ";
	while (result != NULL) {
		cout << result->val << " ";
		result = result->next;
	}
	cout << endl;

	nums = { 1, 1, 1 };
	ptr = &head;
	for (auto&& x : nums) {
		*ptr = new ListNode(x);
		ptr = &((*ptr)->next);
	}
	result = sln.deleteDuplicates(head);
	cout << "result = ";
	while (result != NULL) {
		cout << result->val << " ";
		result = result->next;
	}
	cout << endl;

	nums = { 1, 1, 2,2,2 };
	ptr = &head;
	for (auto&& x : nums) {
		*ptr = new ListNode(x);
		ptr = &((*ptr)->next);
	}
	result = sln.deleteDuplicates(head);
	cout << "result = ";
	while (result != NULL) {
		cout << result->val << " ";
		result = result->next;
	}
	cout << endl;

	nums = { 1, 1, 2,2,2,3 };
	ptr = &head;
	for (auto&& x : nums) {
		*ptr = new ListNode(x);
		ptr = &((*ptr)->next);
	}
	result = sln.deleteDuplicates(head);
	cout << "result = ";
	while (result != NULL) {
		cout << result->val << " ";
		result = result->next;
	}
	cout << endl;

	nums = { 1, 1, 2,3,3,3 };
	ptr = &head;
	for (auto&& x : nums) {
		*ptr = new ListNode(x);
		ptr = &((*ptr)->next);
	}
	result = sln.deleteDuplicates(head);
	cout << "result = ";
	while (result != NULL) {
		cout << result->val << " ";
		result = result->next;
	}
	cout << endl;
}