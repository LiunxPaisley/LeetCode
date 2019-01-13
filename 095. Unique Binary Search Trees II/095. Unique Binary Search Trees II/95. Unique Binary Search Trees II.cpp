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
	vector<TreeNode*> generateTrees(int n) {
		if (!n) return{};
		return generate(1, n);
	}
private:
	vector<TreeNode*> generate(int start, int end) {
		vector<TreeNode*> res;
		if (start > end) {
			res.push_back(nullptr);
		} else if (start == end) { 
			res.push_back(new TreeNode(start)); 
		} else {
			for (int i = start; i <= end; ++i) {
				vector<TreeNode*> l = generate(start, i - 1);
				vector<TreeNode*> r = generate(i + 1, end);
				for (int j = 0; j < l.size(); ++j) {
					for (int k = 0; k < r.size(); ++k) {
						TreeNode* h = new TreeNode(i);
						h->left = l[j];
						h->right = r[k];
						res.push_back(h);
					}
				}
			}
		}
		return res;
	}
};

void print_tree(TreeNode* root) {
	if (root) {
		cout << root->val << ", ";
		print_tree(root->left);
		print_tree(root->right);
	} else {
		cout << " , ";
	}
}


int main() {
	Solution sln;
	int n;
	vector<TreeNode*> result;

	n = 3;
	result = sln.generateTrees(n);
	for (auto&& x : result) {
		print_tree(x);
		cout << endl;
	}
	cout << endl;
}