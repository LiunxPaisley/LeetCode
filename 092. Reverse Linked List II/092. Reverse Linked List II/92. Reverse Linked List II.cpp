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
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		ListNode *dummy = new ListNode(-1), *pre = dummy;
		dummy->next = head;
		for (int i = 0; i < m - 1; ++i) pre = pre->next;
		ListNode *cur = pre->next;
		for (int i = m; i < n; ++i) {
			ListNode *t = cur->next;
			cur->next = t->next;
			t->next = pre->next;
			pre->next = t;
		}
		return dummy->next;
	}
};


int main() {
	Solution sln;
	vector<int> nums;
	ListNode* head;
	ListNode* result;
	int m = 0;
	int n = 0;

	nums = {1,2,3,4,5};
	m = 1;
	n = 5;
	ListNode** p = &head;
	for(auto&& x:nums) {
		*p = new ListNode(x);
		p = &((*p)->next);
	}
	ListNode* iter = head;
	while (iter) {
		cout << iter->val << " ";
		iter = iter->next;
	}
	
	result = sln.reverseBetween(head, m, n);
	cout << endl << "result = ";
	while (result) {
		cout << result->val << " ";
		result = result->next;
	}
	cout << endl;
}