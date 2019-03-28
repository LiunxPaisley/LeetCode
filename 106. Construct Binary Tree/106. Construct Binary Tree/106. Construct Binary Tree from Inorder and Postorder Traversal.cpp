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
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		return buildTree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
	}
private:
	TreeNode* buildTree(const vector<int>& inorder, int in_left, int in_right, 
		const vector<int>& postorder, int post_left, int post_right) {
		if (in_left > in_right || post_left > post_right) return NULL;
		TreeNode* root = new TreeNode(postorder[post_right]);
		int i = 0;
		for (i = in_left; i < in_right && inorder[i] != postorder[post_right]; ++i);
		int len = i - in_left;
		root->left = buildTree(inorder, in_left, i - 1, postorder, post_left, post_left + len - 1);
		root->right = buildTree(inorder, i + 1, in_right, postorder, post_left + len, post_right - 1);
		return root;
	}
};


int main() {
	Solution sln;
	vector<int> postorder;
	vector<int> inorder;
	TreeNode* root;

	postorder = { 9,15,7,20,3 };
	inorder = { 9,3,15,20,7 };
	root = sln.buildTree(inorder, postorder);
	print_tree(root);
	cout << "\n";
}