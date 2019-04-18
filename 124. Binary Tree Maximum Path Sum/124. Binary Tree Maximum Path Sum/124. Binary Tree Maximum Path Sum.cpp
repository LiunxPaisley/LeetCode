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
	int maxPathSum(TreeNode* root) {
		int res = INT_MIN;
		walk(root, res);
		return res;
	}
private:
	int walk(TreeNode* root, int& res) {
		if (!root) return 0;
		int l = walk(root->left, res);
		int r = walk(root->right, res);
		l = max(l, 0);
		r = max(r, 0);
		int total = l + r + root->val;
		res = max(res, total);
		return root->val + max(l, r);
	}
};


int main() {
	Solution sln;
	TreeNode* root;
	vector<int> nums;

	nums = { -10,9,20,INT_MIN,INT_MIN,15,7 };
	make_tree(&root, nums);
	print_tree(root);
	cout << "\nresult: ";
	cout << sln.maxPathSum(root) << endl;

	nums = { 1, -2, -3, 1, 3, -2, INT_MIN, -1 };
	make_tree(&root, nums);
	print_tree(root);
	cout << "\nresult: ";
	cout << sln.maxPathSum(root) << endl;
}