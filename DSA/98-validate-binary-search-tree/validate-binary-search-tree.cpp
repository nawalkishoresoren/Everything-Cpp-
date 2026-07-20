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
    bool check(TreeNode* root, TreeNode* left, TreeNode* right)
    {
        if(root == nullptr)
            return true;

        if(left!=nullptr and left->val >= root->val)
            return false;
        
        if(right!=nullptr and root->val >= right->val)
            return false;


        return check(root->left,left,root) and check(root->right,root,right);
    }
    bool isValidBST(TreeNode* root) 
    {
        return check(root,nullptr,nullptr);
    }
};