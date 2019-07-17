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
* Definition for a binary tree node.
*/
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void make_tree(TreeNode** root, vector<int>& nums, int& i) {
    if (nums[i] != INT_MIN) {
        *root = new TreeNode(nums[i]);
        make_tree(&((*root)->left), nums, ++i);
        make_tree(&((*root)->right), nums, ++i);
    }
}

void make_tree(TreeNode** root, vector<int>& nums) {
    queue<TreeNode**> que;
    que.push(root);
    int i = 0;
    while (i < nums.size()) {
        TreeNode** root = que.front();
        if (nums[i] != INT_MIN) {
            *root = new TreeNode(nums[i]);
            que.push(&((*root)->left));
            que.push(&((*root)->right));
        }
        i++;
        que.pop();
    }
}

void print_tree(TreeNode* root) {
    if (root) {
        print_tree(root->left);
        cout << root->val << " ";
        print_tree(root->right);
    } else {
        cout << "# ";
    }
}

class Solution {
public:
    /**
     * Runtime: 24 ms, faster than 64.86% of C++ online submissions for Kth Smallest Element in a BST.
     * Memory Usage: 21.6 MB, less than 54.50% of C++ online submissions for Kth Smallest Element in a BST.
     */
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* res = kth_smallest(root, k);
        return res->val;
    }
    TreeNode* kth_smallest(TreeNode* root, int& k) {
        if (root) {
            TreeNode* left = kth_smallest(root->left, k);
            if (left) return left;
            k--;
            if (!k) return root;
            TreeNode* right = kth_smallest(root->right, k);
            if (right) return right;
        }
        return NULL;
    }
};


int main() {
    Solution sln;
}