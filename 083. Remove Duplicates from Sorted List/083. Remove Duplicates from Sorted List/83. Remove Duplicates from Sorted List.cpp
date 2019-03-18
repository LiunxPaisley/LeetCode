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
		ListNode** ptr = &head;
		while ((*ptr)->next) {
			ListNode* entry = *ptr;
			if (entry->next->val == entry->val) {
				entry->next = entry->next->next;
			} else {
				ptr = &(entry->next);
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
	result = sln.deleteDuplicates(head);
	cout << "result = ";
	while (result != NULL) {
		cout << result->val << " ";
		result = result->next;
	}
	cout << endl;

	nums = { 1,1,2,3,3 };
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