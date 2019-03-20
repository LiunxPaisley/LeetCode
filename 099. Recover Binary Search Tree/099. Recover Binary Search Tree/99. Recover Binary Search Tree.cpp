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


class Solution {
public:
	void recoverTree(TreeNode* root) {
		inorder(root);
		swap(first->val, second->val);
	}
private:
	TreeNode* pre;
	TreeNode* first;
	TreeNode* second;
	void inorder(TreeNode* root) {
		if (!root) return;
		inorder(root->left);
		if (!pre) pre = root;
		else {
			if (pre->val > root->val) {
				if (!first) {
					first = pre;
				}
				second = root;
			}
			pre = root;
		}
		inorder(root->right);
	}
};


int main() {
	Solution sln;
}