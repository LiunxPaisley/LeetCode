#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        if(!head)
        {
            return nullptr;
        }
        ListNode* ph = head;
        int len = 1;
        while(ph->next)
        {
            ph = ph->next;
            len+=1;
        }

        int step = len - n;
        if(step == 0)
        {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }
        ListNode* ph1 = head;
        ListNode* prev = ph1;
        for(int i = 0; i < step; ++i)
        {
            prev = ph1;
            ph1 = ph1->next;
        }
        prev->next = ph1->next;
        delete ph1;
        return head;
    }
};


int main()
{
    Solution sln;
    ListNode* head = new ListNode(1);
    ListNode* ph = head;
    for(int i = 2; i < 6; ++i){
        ListNode* next = new ListNode(i);
        ph->next = next;
        ph = ph->next;
    }

    ListNode* ph1 = head;
    while(ph1){
        cout << ph1->val << " ";
        ph1 = ph1->next;
    }
    cout << endl;

    int target = 0;
    ListNode* result = sln.removeNthFromEnd(head, 2);

    ListNode* ph2 = result;
    while(ph2){
        cout << ph2->val << " ";
        ph2 = ph2->next;
    }
    cout << endl;
}
