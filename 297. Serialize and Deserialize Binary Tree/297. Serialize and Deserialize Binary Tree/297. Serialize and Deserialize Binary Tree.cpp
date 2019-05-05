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

class Codec {
public:
    /**
     * Runtime: 40 ms, faster than 97.69% of C++ online submissions for Serialize and Deserialize Binary Tree.
     * Memory Usage: 25 MB, less than 89.45% of C++ online submissions for Serialize and Deserialize Binary Tree.
     */
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return {};
        queue<TreeNode*> que;
        string res;
        que.push(root);
        while (!que.empty()) {
            TreeNode* node = que.front();
            que.pop();
            if (!node) {
                res += "#,";
                continue;
            }
            res += to_string(node->val) + ",";
            que.push(node->left);
            que.push(node->right);
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        //cout << "data: " << data << endl;
        if (data.empty()) return NULL;
        // stringstream ss;
        // ss << data;
        char cur = 0;
        int num = 0;
        int offset = 0;
        TreeNode* root = NULL;
        queue<TreeNode**> que;
        que.push(&root);
        while (!que.empty()) {
            // ss >> cur;
            TreeNode** node = que.front();
            que.pop();
            size_t pos = data.find_first_of(',', offset);
            string tmp = data.substr(offset, pos - offset);
            offset = pos + 1;
            if (tmp == "#") continue;

            num = stoi(tmp);
            *node = new TreeNode(num);
            que.push(&((*node)->left));
            que.push(&((*node)->right));
        }
        return root;
    }
};


int main() {
    // Your Codec object will be instantiated and called as such:
    TreeNode* root;
    vector<int> nums;
    string res;
    TreeNode* tree;
    Codec codec;

    nums = { 1,2,3,INT_MIN,INT_MIN,4,5 };
    make_tree(&root, nums);
    res = codec.serialize(root);
    cout << "res : " << res << endl;
    tree = codec.deserialize(res);
    print_tree(tree);
    cout << endl;

    nums = {1,-1,2,-2};
    make_tree(&root, nums);
    res = codec.serialize(root);
    cout << "res : " << res << endl;
    tree = codec.deserialize(res);
    print_tree(tree);
    cout << endl;
}