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
	ListNode* rotateRight(ListNode* head, int k) {
		if (!head) return head;
		if (!k) return head;
		int len = 0;
		ListNode* p1 = head;
		while (p1 != NULL) {
			++len;
			p1 = p1->next;
		}

		int n = k % len;
		int step = len - n;
		ListNode* p2 = head;
		ListNode* prev = p2;
		while (step) {
			prev = p2;
			p2 = p2->next;
			if (!p2) {
				p2 = head;
			}
			--step;
		}

		ListNode* newhead = p2;
		while (p2->next != NULL) {
			p2 = p2->next;
		}
		p2->next = head;
		prev->next = NULL;
		return newhead;
	}
};


int main() {
	Solution sln;
	

	vector<int> nums;
	int k;
	ListNode** ptr;
	ListNode* head;

	nums = { 1,2,3,4,5 };
	ListNode* p1;
	ptr = &p1;
	for (int i = 0; i < nums.size(); ++i) {
		*ptr = new ListNode(nums[i]);
		ptr = &((*ptr)->next);
	}
	*ptr = NULL;
	k = 5;
	head = sln.rotateRight(p1, k);
	while (head) {
		cout << head->val << " ";
		head = head->next;
	}
	cout << "\n";


	nums = { 1,2,3,4,5,6 };
	ListNode* p2;
	ptr = &p2;
	for (int i = 0; i < nums.size(); ++i) {
		*ptr = new ListNode(nums[i]);
		ptr = &((*ptr)->next);
	}
	*ptr = NULL;
	k = 6;
	head = sln.rotateRight(p2, k);
	while (head) {
		cout << head->val << " ";
		head = head->next;
	}
	cout << "\n";

	nums = { 0,1,2 };
	ListNode* p3;
	ptr = &p3;
	for (int i = 0; i < nums.size(); ++i) {
		*ptr = new ListNode(nums[i]);
		ptr = &((*ptr)->next);
	}
	*ptr = NULL;
	k = 4;
	head = sln.rotateRight(p3, k);
	while (head) {
		cout << head->val << " ";
		head = head->next;
	}
	cout << "\n";
}