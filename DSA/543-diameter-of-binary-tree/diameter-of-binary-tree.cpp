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
    int height(TreeNode* root, int &max_diameter)
    {
        if(root == nullptr)
            return 0;

        int left_height = height(root->left,max_diameter);
        int right_height = height(root->right,max_diameter);

        max_diameter = max(max_diameter,left_height + right_height);
        return 1 + max(left_height,right_height);
    }
    int diameterOfBinaryTree(TreeNode* root) 
    {
        int max_diameter = INT_MIN;
        height(root,max_diameter);
        return max_diameter;
    }
};