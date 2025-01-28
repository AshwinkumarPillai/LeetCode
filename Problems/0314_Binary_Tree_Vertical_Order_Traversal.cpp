class Solution {
public:
    
    static bool compare(pair<int,int>a, pair<int,int>b){
        return a.second < b.second;
    }
    
    void dfs(map<int,vector<pair<int,int>>>& m,TreeNode* root,int i,int j){
        if(!root) return;
        m[i].push_back({root->val,j});
        dfs(m,root->left,i-1,j+1);
        dfs(m,root->right,i+1,j+1);
    }
    
    vector<vector<int>> verticalOrder(TreeNode* root) {
        map<int,vector<pair<int,int>>>m;
        dfs(m,root,0,0);
        vector<vector<int>>ans;
        for(auto p: m){
            vector<int>t;
            sort(p.second.begin(),p.second.end(),compare);
            for(auto v: p.second) t.emplace_back(v.first);
            ans.push_back(t);
        }
        return ans;
    }
};
