#pragma once
/*****************************************************************//**
 * \file   solution_0144.h
 * \brief 二叉树的前序遍历 
 * 给你二叉树的根节点 root ，返回它节点值的 前序 遍历。
 * \author Administrator
 * \date   March 2023
 *********************************************************************/
#include<vector>
#include<stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
 
class solution_0144 {
    void preorder(TreeNode* root, vector<int>& ans) {
        if(root == nullptr) return;
        ans.push_back(root->val);
        if(root->left != nullptr) preorder(root->left, ans);
        if(root->right != nullptr)preorder(root->right, ans);
    }
public:
    /**
     * 递归.
     * 
     * \param root
     * \return 
     */
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        preorder(root, ans);
        return ans;
    }
    /**
     * 迭代.
     * 
     * \param root
     * \return 
     */
    vector<int> preorderTraversal2(TreeNode* root) {
        vector<int> ans;
        if(root == nullptr) return ans;
        stack<TreeNode*> temp;
        while(!temp.empty() || root != nullptr) {
            while(root!=nullptr) {
                ans.emplace_back(root->val);
                temp.emplace(root->right);
                root = root->left;
            }
            root = temp.top();
            temp.pop();
        }
        return ans;
    }
    /**
     * Morris遍历.
     * 1. 如果cur无左孩子，cur向右孩子移动（cur=cur.right)
     * 2. 如果cur有左孩子，找到cur左子树上最右的节点，记为mostright
     *      1. 如果mostright的right指针指向空，让其指向cur，cur向左移动（cur=cur.left）
     *          [遍历完右子树后，回到根节点}
     *      2. 如果mostright的right指针指向cur，让其指向空，cur向右移动（cur=cur.right）
     *          [说明左子树已遍历完，开始遍历右子树]
     * \param root
     * \return 
     */
    vector<int> preorderTraversalMorris(TreeNode* root) {
        vector<int> ans;
        if(root == nullptr) return ans;
        TreeNode* p1 = root, * p2 = nullptr;
        while(p1 != nullptr) {
            p2 = p1->left;
            if(p2 != nullptr) {
                while(p2->right != nullptr&&p2->right!=p1) {    
                    p2 = p2->right;
                }
                if(p2->right == nullptr) {
                    ans.emplace_back(p1->val);
                    p2->right = p1;
                    p1 = p1->left;
                    continue;
                } else {
                    p2->right = nullptr;
                }
            } else {
                ans.emplace_back(p1->val);
            }
            p1 = p1->right;
        }
        return ans;
    }
};

