class Solution {
public:    
    int ans = 0;
    vector<int> dfs(TreeNode* root, int dist){
        if(!root) return {};
        auto p = dfs(root->left,dist);
        auto q = dfs(root->right,dist);
        vector<int> leaf;
        if(!p.size() && !q.size()) return {1};
        for(int i=0;i<p.size();i++) for(int j=0;j<q.size();j++) if(p[i]+q[j] <= dist) ans++;
        for(int i=0;i<p.size();i++){
            p[i]++;
            leaf.push_back(p[i]);
        }
        for(int i=0;i<q.size();i++){
            q[i]++;
            leaf.push_back(q[i]);
        
        }
        return leaf;
    }
    
    int countPairs(TreeNode* root, int dist) {
        if(dist == 1) return 0;
        dfs(root,dist);
        return ans;
    }
};
