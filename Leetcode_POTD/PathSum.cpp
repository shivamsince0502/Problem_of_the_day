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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL)
            return false;
        
        queue<TreeNode*> q; 
        queue<int> sum;
        q.push(root);
        sum.push(root->val);
        while(!q.empty())
        {
            TreeNode* temp = q.front();
            int s1 = sum.front();
            q.pop();
            sum.pop();
            if(temp->left)
            {
                q.push(temp->left);
                sum.push(s1+temp->left->val);
            }
                
            if(temp->right)
            {    
                q.push(temp->right);
                sum.push(s1+temp->right->val);
            }
             if(temp->left==NULL && temp->right==NULL)
            {
                if(s1==targetSum)
                    return true;
            }
            
        }
        return false;
        
    }
    
};
