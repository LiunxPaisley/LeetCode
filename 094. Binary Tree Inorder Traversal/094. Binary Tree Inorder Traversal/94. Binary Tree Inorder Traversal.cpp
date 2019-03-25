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
		vector<int> res;
		_inorder(root, res);
		return res;
	}
private:
	void _inorder(TreeNode*root, vector<int>& res) {
		if (root) {
			_inorder(root->left, res);
			res.push_back(root->val);
			_inorder(root->right, res);
		}
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