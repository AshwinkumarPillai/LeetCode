// Time - O(n) | Space - O(n)
class Solution {
public:
    
    void dfs(vector<int>& nodes, TreeNode* root){
        if(!root) return;
        dfs(nodes, root->left);
        nodes.push_back(root->val);
        dfs(nodes, root->right);
    }
    
    bool isValidBST(TreeNode* root) {
        vector<int>nodes;
        dfs(nodes, root);
        int n = nodes.size();
        for(int i=0;i<n-1;i++){
            if(nodes[i] >= nodes[i+1]) return false;
        }
        return true;
    }
};

// Time - O(n) | Space - O(1)
class Solution {
public:
    
    bool dfs(TreeNode* root, long min, long max){
        if(!root) return true;
        int val = root->val;
        if(val <= min || val >= max) return false;
        if(!dfs(root->left, min, val) || !dfs(root->right, val, max)) return false;
        return true;
    }
    
    bool isValidBST(TreeNode* root) {
        long min = INT_MIN;min--;
        long max = INT_MAX;max++;
        return dfs(root, min, max);
    }
};
