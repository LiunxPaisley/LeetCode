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
	����⻹��һ���ر�����ķ�������Ȼ��Ŀ��ǿ���������в����ڻ���
	�������ǿ����û���˼����������������������ֱ�Ӹ��ԵĿ�ͷ��
	ʼ���������������һ��������ĩβʱ������������һ��������Ŀ�
	ͷ��������������ָ�����ջ���ȣ�����ֻ�����������һ�������
	�ڽ��㴦��������һ��������ڸ��Ե�ĩβ�Ŀսڵ㴦��ȡ�Ϊʲô
	һ��������أ���Ϊ����ָ���߹���·����ͬ������������ĳ���֮
	�ͣ�����һ������ȡ�
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