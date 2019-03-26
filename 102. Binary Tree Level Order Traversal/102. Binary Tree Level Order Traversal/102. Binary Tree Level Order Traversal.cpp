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
	vector<vector<int>> levelOrder(TreeNode* root) {
		if (!root) return { {} };
		queue<TreeNode*> que;
		vector<vector<int>> res;
		que.push(root);
		int count = 1;
		while (!que.empty()) {
			vector<int> vec{};
			int cnt = count;
			count = 0;
			for (int i = 0; i < cnt; ++i) {
				TreeNode* tmp = que.front();
				vec.push_back(tmp->val);
				que.pop();
				if (tmp->left) {
					que.push(tmp->left);
					count++;
				}
				if (tmp->right) {
					que.push(tmp->right);
					count++;
				}
			}
			res.push_back(vec);
		}
		return res;
	}
};


int main() {
	Solution sln;
	vector<int> nums;
	vector<vector<int>> res;
	TreeNode* root;

	nums = { 3,9,20,INT_MIN,INT_MIN,15,7 };
	make_tree(&root, nums);
	print_tree(root);
	cout << "\n";
	res = sln.levelOrder(root);
	for (auto&& x : res) {
		for (auto&& y : x) {
			cout << y << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}