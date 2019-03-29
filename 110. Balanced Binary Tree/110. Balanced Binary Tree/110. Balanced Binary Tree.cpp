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
	bool isBalanced(TreeNode* root) {
		if (!root) return true;
		if (!(root->left) && !(root->right)) return true;
		
		int diff = std::abs(depth(root->left) - depth(root->right));

		return !(diff > 1) && isBalanced(root->left) && isBalanced(root->right);
	}
private:
	int depth(TreeNode* root) {
		if (!root) return 0;
		return 1 + max(depth(root->left), depth(root->right));
	}
};


int main() {
	Solution sln;
	vector<int> nums;
	TreeNode* root;

	nums = { 3,9,20,INT_MIN,INT_MIN,15,7 };
	make_tree(&root, nums);
	print_tree(root);
	cout << "\n result: \n";
	cout << sln.isBalanced(root) << endl;

	nums = { 1,2,2,3,INT_MIN,INT_MIN,3,4,INT_MIN,INT_MIN,4 };
	make_tree(&root, nums);
	print_tree(root);
	cout << "\n result: \n";
	cout << sln.isBalanced(root) << endl;
}