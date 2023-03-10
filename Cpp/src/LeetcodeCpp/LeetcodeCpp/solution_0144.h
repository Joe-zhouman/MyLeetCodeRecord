#pragma once
/*****************************************************************//**
 * \file   solution_0144.h
 * \brief ��������ǰ����� 
 * ����������ĸ��ڵ� root ���������ڵ�ֵ�� ǰ�� ������
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
     * �ݹ�.
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
     * ����.
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
     * Morris����.
     * 1. ���cur�����ӣ�cur���Һ����ƶ���cur=cur.right)
     * 2. ���cur�����ӣ��ҵ�cur�����������ҵĽڵ㣬��Ϊmostright
     *      1. ���mostright��rightָ��ָ��գ�����ָ��cur��cur�����ƶ���cur=cur.left��
     *          [�������������󣬻ص����ڵ�}
     *      2. ���mostright��rightָ��ָ��cur������ָ��գ�cur�����ƶ���cur=cur.right��
     *          [˵���������ѱ����꣬��ʼ����������]
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

