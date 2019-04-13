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
	void flatten(TreeNode* root) {
		if (root) {
			queue<TreeNode*> que;
			_flatten(root, que);
			que.pop();
			TreeNode* p = root;
			while (!que.empty()) {
				//TreeNode* tmp = que.front();
				p->right = que.front();
				p->left = NULL;
				p = p->right;
				que.pop();
			}
		}
	}
private:
	void _flatten(TreeNode* root, queue<TreeNode*>& que) {
		if (root) {
			que.push(root);
			_flatten(root->left, que);
			_flatten(root->right, que);
		}
	}
};


int main() {
	Solution sln;
	vector<int> nums;
	TreeNode* root;

	nums = { 1,2,5,3,4,INT_MIN,6 };
	make_tree(&root, nums);
	print_tree(root);
	cout << endl << "result: ";
	sln.flatten(root);
	print_tree(root);
	cout << endl;
}