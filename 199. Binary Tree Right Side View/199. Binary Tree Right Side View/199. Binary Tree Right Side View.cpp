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

/**
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions for Binary Tree Right Side View.
 * Memory Usage: 9.6 MB, less than 52.81% of C++ online submissions for Binary Tree Right Side View. 
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};
        vector<int> ret{};
        queue<TreeNode*> que;
        que.push(root);
        int count = 1;
        while (!que.empty()) {
            int cnt = count;
            count = 0;
            TreeNode* node = que.back();
            ret.push_back(node->val);
            while (cnt != 0) {
                cnt--;
                TreeNode* tmp = que.front();
                que.pop();
                if (tmp->left) {
                    que.push(tmp->left); count++;
                }
                if (tmp->right) {
                    que.push(tmp->right); count++;
                }
            }
        }
        return ret;
    }
};


int main() {
    Solution sln;
}