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
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		if (!root) return {};
		vector<vector<int>> res;
		vector<int> tmp;
		get_path(res, tmp, root, sum);
		return res;
	}
private:
	void get_path(vector<vector<int>>& res, vector<int>& tmp, TreeNode* root, int sum) {
		if (!root) return;
		int newsum = sum - root->val;
		tmp.push_back(root->val);
		if (!newsum && !(root->left) && !(root->right)) {
			res.push_back(tmp);
			tmp.pop_back();
			return;
		}
		get_path(res, tmp, root->left, newsum);
		get_path(res, tmp, root->right, newsum);
		tmp.pop_back();
	}
};


int main() {
	Solution sln;
}