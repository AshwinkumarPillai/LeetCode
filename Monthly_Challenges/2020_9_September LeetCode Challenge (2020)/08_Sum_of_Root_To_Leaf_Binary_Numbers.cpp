// Iterative - 
class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
        int ans = 0,curr = 0;
        stack<pair<TreeNode*,int>>st;
        st.push({root,0});
        while(!st.empty()){
            auto node = st.top().first;
            curr = st.top().second;st.pop();
            if(node){
                curr = curr<<1 | node->val;
                if(!node->left && !node->right) ans += curr;
                else{
                    st.push({node->right,curr});
                    st.push({node->left,curr});
                }
            }
        }
        return ans;
    }
};


// Recursive - 

// Bit Manipulation
class Solution {
public:
    int ans;
    void dfs(TreeNode* root,int curr){
        if(!root) return;
        curr = (curr << 1) | root->val;
        if(!root->left && !root->right) ans += curr;
        dfs(root->left,curr);
        dfs(root->right,curr);
    }
    int sumRootToLeaf(TreeNode* root) {
        ans = 0;
        dfs(root,0);
        return ans;
    }
};

// multiply by 2
class Solution {
public:
    int ans;
    
    void dfs(TreeNode* root,int& n){
        if(!root) return;
        n *= 2;
        n += root->val;
        if(!root->left && !root->right) ans += n;
        dfs(root->left,n);
        dfs(root->right,n);
        n -= root->val;
        n /= 2;
    }
    
    int sumRootToLeaf(TreeNode* root) {
        ans = 0;
        int n = 0;
        dfs(root,n);
        return ans;
    }
};
