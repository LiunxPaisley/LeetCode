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
     * Runtime: 16 ms, faster than 99.15% of C++ online submissions for Diameter of Binary Tree.
     * Memory Usage: 19.7 MB, less than 100.00% of C++ online submissions for Diameter of Binary Tree.
     */
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        int res = INT_MIN;
        walk(root, res);
        return res;
    }
private:
    int walk(TreeNode* root, int& res) {
        if (root) {
            int a = walk(root->left, res) + 1;
            int b = walk(root->right, res) + 1;
            res = max(res, a + b - 2);
            return max(a, b);
        }
        return 0;
    }
};


int main() {
    Solution sln;
}