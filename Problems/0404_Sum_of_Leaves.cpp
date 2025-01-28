class Solution {
public:
    int sum = 0;
    void dfs(TreeNode* root,bool isleft){
        if(!root->left && !root->right){
            if(isleft) sum += root->val;
            return;
        }
        if(root->left) dfs(root->left,true);
        if(root->right) dfs(root->right,false);
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) return 0;
        dfs(root,false);
        return sum;
    }
};
