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
     * Runtime: 12 ms, faster than 99.19% of C++ online submissions for House Robber III.
     * Memory Usage: 20.7 MB, less than 75.89% of C++ online submissions for House Robber III.
     */
    int rob(TreeNode* root) {
        int l = 0, r = 0;
        return dfs(root, l, r);
    }
    int dfs(TreeNode* root, int& l, int& r) {
        if (!root) return 0;
        int ll = 0, lr = 0, rl = 0, rr = 0;
        l = dfs(root->left, ll, lr);
        r = dfs(root->right, rl, rr);
        return max(root->val + ll + lr + rl + rr, l + r);
    }
};


int main() {
    Solution sln;
}