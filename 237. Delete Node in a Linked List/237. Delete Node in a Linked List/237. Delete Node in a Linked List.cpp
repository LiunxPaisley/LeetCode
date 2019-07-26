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
     * Runtime: 12 ms, faster than 83.45% of C++ online submissions for Delete Node in a Linked List.
     * Memory Usage: 9.2 MB, less than 50.80% of C++ online submissions for Delete Node in a Linked List.
     */
    void deleteNode(ListNode* node) {
        ListNode* prev = NULL;
        while (node->next) {
            node->val = node->next->val;
            prev = node;
            node = node->next;
        }
        prev->next = NULL;
        delete node;
    }
};


int main() {
    Solution sln;
}