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
    vector<int> rightSideView(TreeNode* root) 
    {
        if(root == nullptr)
            return {};
        vector<int>ans;
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty())
        {
            int qsize = q.size();
            ans.push_back(q.back()->val);
            while(qsize>0)
            {
                auto temp = q.front();
                q.pop();
                qsize--;

                if(temp->left)
                    q.push(temp->left);
                
                if(temp->right)
                    q.push(temp->right);
            }
        }
        return ans;
    }
};