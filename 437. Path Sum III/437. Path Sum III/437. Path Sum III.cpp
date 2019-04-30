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
     * Runtime: 40 ms, faster than 18.33% of C++ online submissions for Path Sum III.
     * Memory Usage: 14.6 MB, less than 100.00% of C++ online submissions for Path Sum III.
     */
    int pathSum(TreeNode* root, int sum) {
        int count = 0;
        dfs(root, sum, count);
        return count;
    }
private:
    void dfs(TreeNode* root, int sum, int& count) {
        if (!root) return;

        dfs_from(root, sum, count);
        dfs(root->left, sum, count);
        dfs(root->right, sum, count);
    }
    void dfs_from(TreeNode* root, int sum, int& count) {
        if (!root) return;
        if (root->val == sum) {
            count++;
        }
        dfs_from(root->left, sum - root->val, count);
        dfs_from(root->right, sum - root->val, count);
    }
};


int main() {
    Solution sln;
}