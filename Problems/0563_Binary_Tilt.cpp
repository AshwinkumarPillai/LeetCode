class Solution {
public:
    int ans = 0;
    int dfs(TreeNode* root){
        if(!root) return 0;
        int l = dfs(root->left);
        int r = dfs(root->right);
        ans += abs(r-l);
        return l + r + root->val;
    }
    
    int findTilt(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
