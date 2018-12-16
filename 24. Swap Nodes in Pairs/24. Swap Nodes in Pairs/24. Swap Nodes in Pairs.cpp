#include <iostream>
#include <vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
	int       val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		ListNode** ptr = &head;
		while (*ptr) {
			if ((*ptr)->next == NULL) {
				break;
			}
			ListNode* next = (*ptr)->next;
			(*ptr)->next = next->next;
			next->next = *ptr;
			*ptr = next;
			ptr = &((*ptr)->next->next);
		}
		return head;
	}
};

int main() {
	Solution sln;
	vector<int> v{1,2,3,4,5,6,7};

	ListNode* head;
	ListNode** p = &head;
	for (int i = 0; i < v.size(); ++i) {
		*p = new ListNode(v[i]);
		p = &((*p)->next);
	}

	ListNode* result = sln.swapPairs(head);

	ListNode* ptr = result;
	while (ptr) {
		cout << ptr->val << " ";
		ptr = ptr->next;
	}
}