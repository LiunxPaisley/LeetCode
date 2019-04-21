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
	这道题还有一种特别巧妙的方法，虽然题目中强调了链表中不存在环，
	但是我们可以用环的思想来做，我们让两条链表分别从各自的开头开
	始往后遍历，当其中一条遍历到末尾时，我们跳到另一个条链表的开
	头继续遍历。两个指针最终会相等，而且只有两种情况，一种情况是
	在交点处相遇，另一种情况是在各自的末尾的空节点处相等。为什么
	一定会相等呢，因为两个指针走过的路程相同，是两个链表的长度之
	和，所以一定会相等。
	*/
	/**
	 * Runtime: 52 ms, faster than 98.21% of C++ online submissions for Intersection of Two Linked Lists.
     * Memory Usage: 16.7 MB, less than 73.83% of C++ online submissions for Intersection of Two Linked Lists.
	 */
	ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
		if (!headA || !headB) return NULL;
		ListNode * a = headA, *b = headB;
		while (a != b) {
			a = a ? a->next : headB;
			b = b ? b->next : headA;
		}
		return a;
	}
	/**
	 * Runtime : 60 ms, faster than 36.07% of C++ online submissions for Intersection of Two Linked Lists.
	 * Memory Usage : 16.7 MB, less than 60.43% of C++ online submissions for Intersection of Two Linked Lists.
	 */
	ListNode* getIntersectionNode1(ListNode* headA, ListNode* headB) {
		int len_a = 0, len_b = 0;
		ListNode* p_a = headA;
		ListNode* p_b = headB;
		while (p_a) {
			len_a++;
			p_a = p_a->next;
		}
		while (p_b) {
			len_b++;
			p_b = p_b->next;
		}
		p_a = headA, p_b = headB;
		if (len_a > len_b) {
			int diff = len_a - len_b;
			while (diff-- && p_a) {
				p_a = p_a->next;
			}
		} else {
			int diff = len_b - len_a;
			while (diff-- && p_b) {
				p_b = p_b->next;
			}
		}
		while (p_a && p_b) {
			if (p_a == p_b) {
				break;
			}
			p_a = p_a->next;
			p_b = p_b->next;
		}
		return p_a;
	}
};


int main() {
	Solution sln;
}