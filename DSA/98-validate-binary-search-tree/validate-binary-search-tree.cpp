/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool check_valid(TreeNode* root, TreeNode* left, TreeNode* right)
    {
        if(root == nullptr)
            return true;

        if(left!=nullptr and left->val>=root->val)
            return false;
        if(right!=nullptr and right->val<=root->val)
            return false;

        return check_valid(root->left,left,root) and check_valid(root->right,root,right);
    }
    bool isValidBST(TreeNode* root) 
    {
        return check_valid(root,nullptr,nullptr);
    }
};