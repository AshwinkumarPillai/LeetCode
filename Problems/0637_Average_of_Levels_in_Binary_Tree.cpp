// BFS
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>ans;
        queue<TreeNode*>q;
        q.push(root);
        double sum = 0;
        while(!q.empty()){
            int sz = q.size();
            for(int i=0;i<sz;i++){
                TreeNode* node = q.front();q.pop();
                sum += node->val;
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
            ans.push_back(sum / sz);
            sum = 0;
        }
        return ans;
    }
};

// DFS
class Solution {
public:
    
    void calcLevels(vector<pair<double,double>> &levels, TreeNode* root,int level){
        if(!root) return;
        if(level >= levels.size()){
            levels.push_back({1,root->val});
        }else{
            levels[level].first++;
            levels[level].second += root->val;
        }
        calcLevels(levels,root->left,level+1);
        calcLevels(levels,root->right,level+1);
    }
    
    vector<double> averageOfLevels(TreeNode* root) {
        vector<pair<double,double>>levels;
        vector<double>ans;
        calcLevels(levels,root,0);
        for(auto x: levels){
            ans.push_back(x.second / x.first);
        }
        return ans;
    }
};
