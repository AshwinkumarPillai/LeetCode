class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*>q;
        int level = 0;
        q.push(root);
        vector<vector<int>>ans;
        while(!q.empty()){
            int sz = q.size();
            vector<int>t;
            while(sz--){
                TreeNode* node = q.front();q.pop();
                t.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            if(level&1) reverse(t.begin(),t.end());
            ans.push_back(t);
            level++;
        }
        return ans;
    }
};