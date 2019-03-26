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
	bool isSymmetric(TreeNode* root) {
		if (!root) return true;
		return is_symmetric(root->left, root->right);
	}
private:
	bool is_symmetric(TreeNode* left, TreeNode* right) {
		if (!left && right) return false;
		if (left && !right) return false;
		if (left && right) {
			if (left->val != right->val) {
				return false;
			}
			return is_symmetric(left->left, right->right) &&
				is_symmetric(left->right, right->left);
		}
		return true;
	}
};


int main() {
	Solution sln;
	vector<int> nums;
	TreeNode* root;

	nums = {1,2,2,3,4,4,3};
	make_tree(&root, nums);
	print_tree(root);
	cout << "\nis symmetric: " << sln.isSymmetric(root) << endl;

	nums = { 1,2,2,INT_MIN,3,INT_MIN,3 };
	make_tree(&root, nums);
	print_tree(root);
	cout << "\nis symmetric: " << sln.isSymmetric(root) << endl;
}