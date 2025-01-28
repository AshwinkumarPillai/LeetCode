class Solution {
public:
    vector<int>flips = {};
    int i = 0;
    bool dfs(TreeNode* root, vector<int>& v){
        if(!root) return true;
        if(root->val != v[i++]) return false;
        TreeNode* left = root->left,*right = root->right;
        if(left && left->val != v[i]){
            flips.push_back(root->val);
            return dfs(right,v) && dfs(left,v);
        }
        return dfs(left,v) && dfs(right,v);
    }
    
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        return dfs(root,voyage) ? flips : vector<int>() = {-1};
    }
};
