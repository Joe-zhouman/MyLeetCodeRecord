// Joe
// 周漫
// 2020072811:09


#pragma once
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

namespace max_depth {
	struct tree_node {
		int val;
		tree_node* left;
		tree_node* right;

		tree_node(int x) : val(x),
		                   left(nullptr),
		                   right(nullptr) {}
	};

	class solution {
	public:
		int recurse(tree_node* root) const {
			return root == nullptr ? 0 : max(recurse(root->left), recurse(root->right)) + 1;
		}
		int breadth_first_search(tree_node* root) {
			if (root == nullptr)
				return 0;
			std::queue<tree_node*> layer_nodes;
			layer_nodes.push(root);
			int ans = 0;
			while (!layer_nodes.empty()) {
				int n_nodes = layer_nodes.size();
				while (n_nodes>0) {
					auto* temp = layer_nodes.front();
					layer_nodes.pop();
					if (temp->left)
						layer_nodes.push(temp->left);
					if (temp->right)
						layer_nodes.push(temp->right);
					n_nodes--;
				}
				ans++;
			}
			return ans;
		}
	};
}
