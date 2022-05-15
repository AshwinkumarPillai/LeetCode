//DFS
class Solution {
public:
    
    void dfs(vector<vector<int>>& levels, TreeNode* root, int level){
        if(!root) return;
        if(levels.size() == level) levels.push_back({});
        levels[level].push_back(root->val);
        dfs(levels, root->left, level+1);
        dfs(levels, root->right, level+1);
    }
    
    int deepestLeavesSum(TreeNode* root) {
        vector<vector<int>>levels;
        dfs(levels, root, 0);
        int ans = 0;
        for(int x: levels[levels.size() - 1]) ans += x;
        return ans;
    }
};

// BFS
class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int ans = root->val;
        while(!q.empty()){
            int sz = q.size();
            int sum = 0;
            while(sz--){
                TreeNode* node = q.front();q.pop();
                if(node->left){ 
                    sum += node->left->val;
                    q.push(node->left);
                }
                if(node->right){ 
                    sum += node->right->val;
                    q.push(node->right);
                }
            }
            ans = (sum == 0) ? ans : sum;
        }
        return ans;
    }
};
