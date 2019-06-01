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

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
class Solution {
public:
    /**
     * Runtime: 52 ms, faster than 97.75% of C++ online submissions for Populating Next Right Pointers in Each Node.
     * Memory Usage: 27.8 MB, less than 5.04% of C++ online submissions for Populating Next Right Pointers in Each Node.
     */
    Node* connect(Node* root) {
        if (!root) return NULL;
        queue<Node*> que;
        que.push(root);
        int a = 0;
        while (!que.empty()) {
            int count = pow(2, a) - 1;
            while (count--) {
                Node* n = que.front();
                que.pop();
                n->next = que.front();
                if (n->left) que.push(n->left);
                if (n->right) que.push(n->right);
            }
            Node* n = que.front();
            que.pop();
            n->next = NULL;
            if (n->left) que.push(n->left);
            if (n->right) que.push(n->right);
            a++;
        }
        return root;
    }
};


int main() {
    Solution sln;
}