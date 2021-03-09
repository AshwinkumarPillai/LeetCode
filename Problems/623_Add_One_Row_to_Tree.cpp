// BFS
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if(d == 1){
            TreeNode* head = new TreeNode(v,root,NULL);
            return head;
        }
        queue<TreeNode*>q;
        q.push(root);
        int l = 1;
        while((l < d-1) && !q.empty()){
            int sz = q.size();
            while(sz--){
                TreeNode* node = q.front();q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            l++;
        }
        while(!q.empty()){
            TreeNode* node = q.front();q.pop();
            TreeNode* leftNode = new TreeNode(v,node->left,NULL);
            TreeNode* rightNode = new TreeNode(v,NULL,node->right);
            node->left = leftNode;
            node->right = rightNode;
        }
        return root;
    }
};


// DFS
class Solution {
public:
    int gv,gd;
    void dfs(TreeNode* root, int level){
        if(!root) return;
        if(level == gd){
            TreeNode* leftNode = new TreeNode(gv,root->left,NULL);
            TreeNode* rightNode = new TreeNode(gv,NULL,root->right);
            root->left = leftNode;
            root->right = rightNode;
            return;
        }
        dfs(root->left,level+1);
        dfs(root->right,level+1);
    }
    
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        gv = v;gd = d-1;
        if(d == 1){
            TreeNode* head = new TreeNode(v,root,NULL);
            return head;
        }
        dfs(root,1);
        return root;
    }
};
