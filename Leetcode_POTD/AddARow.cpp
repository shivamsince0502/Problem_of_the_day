class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int d) {
        queue<TreeNode*> bq;
        queue<int> dq;
        bq.push(root);
        dq.push(1);
        if(d == 1) {
            TreeNode* temp = new TreeNode(val);
            temp->left = root;
            return temp;
        }
        while(!bq.empty()) {
            TreeNode* node = bq.front();
            bq.pop();
            int level = dq.front();
            dq.pop();
            if(level == d-1) {
                
                TreeNode* ld = new TreeNode(val);
                ld->left = node->left;
                node->left = ld;
                bq.push(ld);
                dq.push(level+1);

                TreeNode* rd = new TreeNode(val);
                rd->right = node->right;
                node->right = rd;
                bq.push(rd);
                dq.push(level+1);
                
            }else{
                if(node->left) {
                    bq.push(node->left);
                    dq.push(level+1);
                }
                if(node->right) {
                    bq.push(node->right);
                    dq.push(level+1);
                }
            }
        }
        return root;
    }
};
