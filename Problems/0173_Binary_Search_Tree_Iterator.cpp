class BSTIterator {
public:
    
    vector<int>arr;
    int i = -1;
    int n;
    
    void dfs(TreeNode* root){
        if(!root) return;
        dfs(root->left);
        arr.emplace_back(root->val);
        dfs(root->right);
    }
    
    BSTIterator(TreeNode* root) {
        dfs(root);
        n = arr.size();
    }
    
    int next() {
        i++;
        return arr[i];
    }
    
    bool hasNext() {
        return i < n-1;
    }
};
