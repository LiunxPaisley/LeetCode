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
     * Runtime: 12 ms, faster than 98.44% of C++ online submissions for Odd Even Linked List.
     * Memory Usage: 9.7 MB, less than 60.20% of C++ online submissions for Odd Even Linked List.
     */
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !(head->next)) return head;
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* p1 = odd;
        ListNode* p2 = even;
        ListNode* p = even->next;
        int count = 3;
        while (p) {
            if (count % 2) {
                p1->next = p;
                p1 = p1->next;

            } else {
                p2->next = p;
                p2 = p2->next;
            }
            p = p->next;
            count++;
        }
        p1->next = even;
        p2->next = NULL;
        return odd;
    }
};


int main() {
    Solution sln;
}