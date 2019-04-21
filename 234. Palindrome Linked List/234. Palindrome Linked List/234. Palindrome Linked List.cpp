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
#include <cctype>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* generate_list(vector<int>& nums) {
	ListNode* head;
	ListNode** ptr = &head;
	for (auto&& x : nums) {
		*ptr = new ListNode(x);
		ptr = &((*ptr)->next);
	}
	return head;
}

void print_list(ListNode* p) {
	while (p) {
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;
}

class Solution {
public:
	/**
	 * Runtime: 24 ms, faster than 98.25% of C++ online submissions for Palindrome Linked List.
     * Memory Usage: 12.7 MB, less than 57.10% of C++ online submissions for Palindrome Linked List.
	 */
	bool isPalindrome(ListNode* head) {
		if (!head || !(head->next)) return true;
		ListNode * fast = head;
		ListNode * slow = head;
		ListNode * pre = slow;
		while (fast && fast->next) {
			pre = slow;
			slow = slow->next;
			fast = fast->next->next;
		}
		if (fast && !(fast->next)) {
			pre = slow;
			slow = slow->next;
		}
		while (slow->next) {
			ListNode* tmp = slow->next;
			slow->next = tmp->next;
			tmp->next = pre->next;
			pre->next = tmp;
		}
		ListNode* p1 = head;
		ListNode* p2 = pre->next;
		while (p2 && p1) {
			if (p1->val != p2->val) {
				return false;
			}
			p1 = p1->next;
			p2 = p2->next;
		}
		return true;
	}
};


int main() {
	Solution sln;
}