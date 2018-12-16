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
	ListNode* reverseKGroup(ListNode* head, int k) {

	}
};

int main() {
	Solution sln;
	vector<int> v{ 1,2,3,4,5,6,7 };

	ListNode* head;
	ListNode** p = &head;
	for (int i = 0; i < v.size(); ++i) {
		*p = new ListNode(v[i]);
		p = &((*p)->next);
	}

	int k = 3;
	ListNode* result = sln.reverseKGroup(head, k);

	ListNode* ptr = result;
	while (ptr) {
		cout << ptr->val << " ";
		ptr = ptr->next;
	}
}