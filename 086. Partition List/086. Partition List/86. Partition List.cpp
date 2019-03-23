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
	ListNode* partition(ListNode* head, int x) {
		if (!head) return head;
		ListNode** less = &head;
		ListNode* result = head;

		while (*less && (*less)->val < x) {
			less = &((*less)->next);
		}
		if (*less) {
			ListNode** iter = &((*less)->next);
			while (*iter) {

				if ((*iter)->val < x) {
					ListNode* temp = *iter;
					*iter = temp->next;
					temp->next = *less;
					*less = temp;
					less = &((*less)->next);
				} else {
					iter = &((*iter)->next);
				}
				/*ListNode* result = head;
				while (result) {
					cout << result->val << " ";
					result = result->next;
				}
				cout << "\n";*/
			}
		}
		return head;
	}
};

int main() {
	Solution sln;
	ListNode* head;
	ListNode* result;
	ListNode** ptr;
	vector<int> nums;
	int x = 0;

	nums = { 1,4,3,2,5,2 };
	ptr = &head;
	for (auto&& x : nums) {
		*ptr = new ListNode(x);
		ptr = &((*ptr)->next);
	}
	x = 3;
	result = sln.partition(head, x);
	cout << "result: ";
	while (result) {
		cout << result->val << " ";
		result = result->next;
	}
	cout << "\n";

	nums = { 1 };
	ptr = &head;
	for (auto&& x : nums) {
		*ptr = new ListNode(x);
		ptr = &((*ptr)->next);
	}
	x = 0;
	result = sln.partition(head, x);
	cout << "result: ";
	while (result) {
		cout << result->val << " ";
		result = result->next;
	}
	cout << "\n";

	nums = { 3,1,2 };
	ptr = &head;
	for (auto&& x : nums) {
		*ptr = new ListNode(x);
		ptr = &((*ptr)->next);
	}
	x = 3;
	result = sln.partition(head, x);
	cout << "result: ";
	while (result) {
		cout << result->val << " ";
		result = result->next;
	}
	cout << "\n";
}