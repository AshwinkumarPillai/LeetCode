class Solution {
public:
    int k,flag = 0;
    void dfs(TreeNode* root){
        if(root == NULL){
            return;
        }
        k -= root->val;
        if(root->left == NULL && root->right == NULL){
            if(k==0){
                flag = 1;
            }
            k+=root->val;
            return;
        }
        dfs(root->left);
        dfs(root->right);
        k+=root->val;
        return;
    }
    bool hasPathSum(TreeNode* root, int sum) {
        k = sum;
        dfs(root);
        return (flag==1);
    }
};