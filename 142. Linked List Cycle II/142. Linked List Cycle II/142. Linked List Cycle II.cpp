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
	ListNode* detectCycle(ListNode* head) {
		if (!head) return NULL;
		ListNode* walker = head;
		ListNode* runner = head;
		int count = 0;
		bool flag = false;
		while (runner->next && runner->next->next) {
			walker = walker->next;
			runner = runner->next->next;
			++count;
			if (walker == runner) {
				flag = true;
				break;
			}
		}
		cout << "count: " << count << endl;
		if (!flag) {
			return NULL;
		}

		walker = head;
		runner = head;
		for (int i = 0; i < count - 1; ++i) {
			runner = runner->next;
		}
		while (runner->next != walker) {
			runner = runner->next;
			walker = walker->next;
		}
		return walker;
	}
};


int main() {
	Solution sln;
	vector<int> nums;
	ListNode* head = NULL;

	nums = { 3,2,0,-4, 6, 7, 8, 9, 10, 11, 43 };
	head = generate_list(nums);
	ListNode* rec = NULL;
	ListNode* p = head;
	for (int i = 0; i < nums.size() - 1; ++i) {
		if (i == 6) {
			rec = p;
		}
		p = p->next;
	}
	p->next = rec;
	p = head;
	for (int i = 0; i < nums.size() + 1; ++i) {
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;

	ListNode* res = sln.detectCycle(head);
	cout << res->val << endl;
}