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
     * Runtime: 24 ms, faster than 95.27% of C++ online submissions for Lowest Common Ancestor of a Binary Tree.
     * Memory Usage: 20.1 MB, less than 12.56% of C++ online submissions for Lowest Common Ancestor of a Binary Tree.
     */
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1, path2;
        dfs(root, p, path1);
        dfs(root, q, path2);
        TreeNode* res = NULL;
        for (int i = 0; i < path1.size() && i < path2.size() && path1[i] == path2[i]; ++i) {
            res = path1[i];
        }
        return res;
    }
private:
    bool dfs(TreeNode* root, TreeNode* target, vector<TreeNode*>& path) {
        if (!root) {
            return false;
        }
        path.push_back(root);
        if (root == target) {
            return true;
        }
        if (root->left) {
            if (dfs(root->left, target, path)) {
                return true;
            } else {
                path.pop_back();
            }
        }
        if (root->right) {
            if (dfs(root->right, target, path)) {
                return true;
            } else {
                path.pop_back();
            }
        }
        return false;
    }
public:    
    /**
     * Runtime: 152 ms, faster than 5.72% of C++ online submissions for Lowest Common Ancestor of a Binary Tree.
     * Memory Usage: 16.9 MB, less than 26.28% of C++ online submissions for Lowest Common Ancestor of a Binary Tree.
     */
    TreeNode* lowestCommonAncestor1(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root) {
            TreeNode* lca = NULL;
            search(root, p, q, lca);
            return lca;
        }
        return NULL;
    }
private:
    bool search(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode*& lca) {
        if (root) {

            int b0 = ((root->val == p->val) || (root->val == q->val));
            int b1 = search(root->left, p, q, lca);
            int b2 = search(root->right, p, q, lca);
            cout << b0 << ", " << b1 << ", " << b2 << endl;
            int res = b0 + b1 + b2;
            if (res == 2) {
                lca = root;
            }
            return (b0 || b1 || b2);
        }
        return false;
    }
};


int main() {
    Solution sln;
}