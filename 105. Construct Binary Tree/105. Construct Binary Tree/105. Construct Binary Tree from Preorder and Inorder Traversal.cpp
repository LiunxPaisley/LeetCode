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
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		TreeNode* root;
		generate(&root, preorder, inorder);
		return root;
	}
private:
	void generate(TreeNode** root, vector<int> preorder, vector<int> inorder) {
		if (preorder.empty()) return;
		/*cout << "preorder: ";
		for (auto&& x : preorder) { cout << x << " "; }
		cout << "\n";
		cout << "inorder: ";
		for (auto&& x : inorder) { cout << x << " "; }
		cout << "\n";*/
		*root = new TreeNode(preorder[0]);
		vector<int>::iterator iter = find(inorder.begin(), inorder.end(), preorder[0]);
		int len = std::distance(inorder.begin(), iter);
		//cout << "len : " << len << endl;
		generate(&((*root)->left), vector<int>(preorder.begin() + 1, preorder.begin() + len + 1), vector<int>(inorder.begin(), iter));
		generate(&((*root)->right), vector<int>(preorder.begin() + len + 1, preorder.end()), vector<int>(iter + 1, inorder.end()));
	}
};


int main() {
	Solution sln;
	vector<int> preorder;
	vector<int> inorder;
	TreeNode* root;

	preorder = { 3,9,20,15,7 };
	inorder = { 9,3,15,20,7 };
	root = sln.buildTree(preorder, inorder);
	print_tree(root);
	cout << "\n";
}