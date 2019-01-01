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
		if (k == 1 || !head) {
			return head;
		}
		ListNode* end = head;
		ListNode* prev = NULL;
		ListNode* begin = NULL;
		
		bool exit = false;
		bool first = true;
		while (!exit) {
			begin = end;
			for (int j = 0; j < k - 1; ++j) {
				if (!end || !(end->next)) {
					exit = true;
					break;
				}
				end = end->next;
				
			}
			
			if (exit) continue;
			for (int i = 0; i < k - 1; ++i) {
				ListNode* temp = begin;
				begin = begin->next;
				if (prev) {
					prev->next = begin;
				}
				temp->next = end->next;
				end->next = temp;
				//begin = begin->next;
				//end = end->next;
			}
			if (first) {
				head = end;
				first = false;
			}
			
			//ListNode* iter = head;
			//while (iter) {
			//	cout << iter->val << " ";
			//	iter = iter->next;
			//}
			//cout << endl;

			for (int h = 0; h < k-1; ++h) {
				end = end->next;
			}
			prev = end;
			end = end->next;
		}

		return head;
	}
};

int main() {
	Solution sln;
	vector<int> v{ 1,2,3,4,5 };

	ListNode* head;
	ListNode** p = &head;
	for (int i = 0; i < v.size(); ++i) {
		*p = new ListNode(v[i]);
		p = &((*p)->next);
	}

	int k = 2;
	ListNode* result = sln.reverseKGroup(head, k);

	ListNode* end = result;
	while (end) {
		cout << end->val << " ";
		end = end->next;
	}
	cout << endl;
}
