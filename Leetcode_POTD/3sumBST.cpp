// 1st unordered map solution
class Solution {
public:
    
    unordered_map<int, int> map;
    bool  solve(TreeNode* root, int k){
        if(root == NULL) return false;
        if(map[k - root->val]) return true;
        map[root->val]++;
        return (solve(root->left, k) || solve(root->right, k));
    }
    
    bool findTarget(TreeNode* root, int k) {
        return solve(root, k);
    }
};


// 2nd two pointers solution

class Solution {
public:
    
    vector<int> arr;
    void solve(TreeNode* root){
        if(root == NULL) return;
        solve(root->left);
        arr.push_back(root->val);
        solve(root->right);
    }
    
    bool findTarget(TreeNode* root, int k) {
        solve(root);
        int i = 0, j = arr.size()-1;
        while(i < j) {
            if((arr[i]+arr[j]) == k) return true;
            else if ((arr[i]+arr[j]) > k) j--;
            else i++;
        }
        return false;
    }
};
