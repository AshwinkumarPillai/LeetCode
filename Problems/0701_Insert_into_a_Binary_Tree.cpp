class Solution {
public:
    void dfs(TreeNode* root,int& val){
        bool less = (val < root->val); 
        if(!root->left && !root->right){
            if(less) root->left = new TreeNode(val);
            else root->right = new TreeNode(val);
            return;
        }
        if(less){
            if(root->left) dfs(root->left,val);
            else{
                root->left = new TreeNode(val);
                return;
            }
        } 
        else{
           if(root->right) dfs(root->right,val);
            else{
                root->right = new TreeNode(val);
                return;
            }
        }
    }
    
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* node = root;
        if(!root) return new TreeNode(val);
        dfs(node,val);
        return root;
    }
};
