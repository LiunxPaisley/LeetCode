#include <iostream>
#include <cstdlib>
#include <cstdio>

struct ListNode {
    int       val;
    ListNode* next;
	ListNode(int x) : val(x), next(NULL){}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode* p1  = l1;
        ListNode* p2  = l2;
        ListNode* ret = new ListNode(0);
        ListNode* p3  = ret;
        int       c   = 0;

        while (p1 != NULL || p2 != NULL || c != 0)
        {
            int temp = 0;
            temp += c;
            if (p1 != NULL)
            {
                temp += p1->val;
                p1 = p1->next;
            }
            if (p2 != NULL)
            {
                temp += p2->val;
                p2 = p2->next;
            }
            c       = temp / 10;
            temp    = temp % 10;
            p3->val = temp;
            if (p1 != NULL || p2 != NULL || c != 0)
            {
                p3->next = new ListNode(0);
                p3       = p3->next;
            }
        }

        return ret;
    }
};

int main() {

}