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
	int maxDepth(TreeNode* root) {
		if (!root) return 0;
		queue<TreeNode*> que;
		que.push(root);
		int depth = 0;
		while (!que.empty()) {
			++depth;
			int curLevelNodesTotal = que.size();
			int cnt = 0;
			while (cnt < curLevelNodesTotal) {
				++cnt;
				root = que.front();
				que.pop();
				if (root->left)
					que.push(root->left);
				if (root->right)
					que.push(root->right);
			}
		}
		return depth;
	}
	int maxDepth1(TreeNode* root) {
		if (!root) return 0;
		return 1 + max(maxDepth(root->left), maxDepth(root->right));
	}
};


int main() {
	Solution sln;
	vector<int> nums;
	TreeNode* root;

	nums = { 3,9,20,INT_MIN,INT_MIN,15,7 };
	make_tree(&root, nums);
	print_tree(root);
	cout << "\nresult: " << sln.maxDepth(root) << endl;
}