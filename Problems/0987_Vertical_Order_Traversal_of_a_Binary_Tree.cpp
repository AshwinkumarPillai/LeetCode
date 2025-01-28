class Solution {
public:
    
    static bool compare(pair<int,int>a,pair<int,int>b){
        if(a.second == b.second){
            return a.first < b.first;
        }
        return a.second < b.second;
    }
    
    void fillMap(TreeNode* root,int i,int j,map<int,vector<pair<int,int>>>&m){
        if(!root) return;
        m[i].push_back({root->val,j});
        fillMap(root->left,i-1,j+1,m);
        fillMap(root->right,i+1,j+1,m);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,vector<pair<int,int>>>m;
        fillMap(root,0,0,m);
        vector<vector<int>>ans;
        for(auto x: m){
            vector<int>t;
            sort(x.second.begin(),x.second.end(),compare);
            for(auto v: x.second) t.push_back(v.first);
            ans.push_back(t);
        }
        return ans;
    }
};
