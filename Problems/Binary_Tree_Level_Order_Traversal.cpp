// BFS traversal
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        queue<pair<TreeNode*,int>>q;
        q.push({root, 0});
        while(!q.empty()){
            TreeNode* node = q.front().first;
            int level = q.front().second;
            if(node){
                if(level >= ans.size()){
                    ans.push_back({});
                }
                ans[level].push_back(node->val);
                q.push({node->left, level+1});
                q.push({node->right, level+1});
            }
            q.pop();
        }
        return ans;
    }
};

// DFS traversal
class Solution {
public:
    
    void dfs(vector<vector<int>> &ans, TreeNode* root, int level){
        if(!root) return;
        if(level >= ans.size()) ans.push_back({});
        ans[level].push_back(root->val);
        dfs(ans, root->left, level+1);
        dfs(ans, root->right, level+1);
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        dfs(ans, root, 0);
        return ans;
    }
};
