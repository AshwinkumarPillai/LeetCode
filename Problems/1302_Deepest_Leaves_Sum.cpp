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
                    sum+= node->left->val;
                    q.push(node->left);
                }
                if(node->right){ 
                    sum+= node->right->val;
                    q.push(node->right);
                }
            }
            ans = (sum == 0) ? ans : sum;
        }
        return ans;
    }
};
