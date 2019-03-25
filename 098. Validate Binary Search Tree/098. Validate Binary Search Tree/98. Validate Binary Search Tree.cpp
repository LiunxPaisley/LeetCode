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

void print_tree(TreeNode* root) {
	if (root) {
		print_tree(root->left);
		cout << root->val << " ";
		print_tree(root->right);
	} else {
		cout << "# ";
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

class Solution {
public:
	bool isValidBST(TreeNode* root) {
		long long max = long long(INT_MIN) - 1;
		return inorder(root, max);
	}
private:
	bool inorder(TreeNode* root, long long& max) {
		if (root) {
			if (!inorder(root->left, max)) {
				return false;
			}
			if (max > root->val) {
				return false;
			} else {
				max = root->val;
			}
			if (!inorder(root->right, max)) {
				return false;
			}
		}
		return true;
	}
};


int main() {
	Solution sln;
	vector<int> nums;
TreeNode* root;

	nums = { 5,1,4,INT_MIN,INT_MIN,3,6 };
	make_tree(&root, nums);
	print_tree(root);
	cout << "\n""result = " << sln.isValidBST(root) << endl;

	nums = { 2,1,3 };
	make_tree(&root, nums);
	print_tree(root);
	cout << "\n""result = " << sln.isValidBST(root) << endl;
}