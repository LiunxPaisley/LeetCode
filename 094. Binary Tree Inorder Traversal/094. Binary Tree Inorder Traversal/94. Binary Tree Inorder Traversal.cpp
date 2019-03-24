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

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void make_tree(TreeNode** root, const vector<int>& nums, int& i) {
	if (nums[i]) {
		*root = new TreeNode(nums[i]);
		make_tree(&((*root)->left), nums, ++i);
		make_tree(&((*root)->right), nums, ++i);
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
	vector<int> inorderTraversal(TreeNode* root) {
		if (!root) return {};
		stack<TreeNode*> stk;
		vector<int> res;
		stk.push(root);
		while (!stk.empty()) {
			TreeNode* tmp = stk.top();
			if (tmp->left) {
				stk.push(tmp->left);
			} else {
				res.push_back(tmp->val);
				stk.pop();
				//if (stk.empty()) {
				//	break;
				//}
				if (tmp->right) {
					stk.push(tmp->right);
				} else {
					if (stk.empty()) {
						break;
					}
					TreeNode* mid = stk.top();
					res.push_back(mid->val);
					stk.pop();
				}
			}
		}
		return res;
	}
};


int main() {
	Solution sln;
	TreeNode* root;
	vector<int> nums;
	vector<int> res;
	int i = 0;

	i = 0;
	nums = { 1, 0, 2, 3, 0, 0, 0 };
	make_tree(&root, nums, i);
	print_tree(root);

	cout << "\nresult = ";
	res = sln.inorderTraversal(root);

	for (auto&& x : res) {
		cout << x << " ";
	}
	cout << endl;

	i = 0;
	nums = { 1, 0, 0 };
	make_tree(&root, nums, i);
	print_tree(root);

	cout << "\nresult = ";
	res = sln.inorderTraversal(root);

	for (auto&& x : res) {
		cout << x << " ";
	}
	cout << endl;

	i = 0;
	nums = { 2, 3, 0, 1, 0, 0 , 0};
	make_tree(&root, nums, i);
	print_tree(root);

	cout << "\nresult = ";
	res = sln.inorderTraversal(root);

	for (auto&& x : res) {
		cout << x << " ";
	}
	cout << endl;
}