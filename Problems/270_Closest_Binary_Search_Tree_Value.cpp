// O(H) solution
class Solution {
public:
    
    int closestValue(TreeNode* root, double target) {
        int val,ans = root->val;
        while(root){
            val = root->val;
            ans = (abs(val-target) < abs(ans - target)) ? val : ans;
            root = (target < val) ? root->left : root->right;
        }
        return ans;
    }
};

// Using DFS
class Solution {
public:
    
    void dfs(TreeNode* root, double target,long double diff,int& ans){
        if(!root) return;
        double x = abs(target - root->val);
        if(x <= diff){
            ans = root->val;
            diff = x;
        }
        if(target == root->val){
            ans = target;
            return;
        }
        else if(root->val > target){
            dfs(root->left,target,diff,ans);
        }else{
            dfs(root->right,target,diff,ans);
        }
    }
    
    int closestValue(TreeNode* root, double target) {
        int ans = 0;
        dfs(root,target,(long)INT_MAX*(long)INT_MAX,ans);
        return ans;
    }
};
