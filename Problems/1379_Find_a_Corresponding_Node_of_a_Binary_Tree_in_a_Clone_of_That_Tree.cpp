// DFS - With Stack (Iterative)
class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if(original == target) return cloned;
        
        stack<TreeNode*> s1, s2;
        TreeNode* trav1 = original, *trav2 = cloned;
        while(!s1.empty() || trav1){
            while(trav1){
                s1.push(trav1);
                s2.push(trav2);
                
                trav1 = trav1->left;
                trav2 = trav2->left;
            }
            
            trav1 = s1.top();s1.pop();
            trav2 = s2.top();s2.pop();
            
            if(trav1 == target) return trav2;
            trav1 = trav1->right;
            trav2 = trav2->right;
        }
        return NULL;
    }
};

// DFS (Recursive)
class Solution {
public:
    
    TreeNode* ans;
    
    void dfs(TreeNode* o, TreeNode* c, TreeNode* t){
        if(!o) return;
        if(o == t) {
            ans = c;
            return;
        }
        dfs(o->left, c->left, t);
        dfs(o->right, c->right, t);
    }
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if(original == target) return cloned;
        dfs(original, cloned, target);
        return ans;
    }
};

// BFS
class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if(original == target) return cloned;
        
        queue<TreeNode*>q1,q2;
        q1.push(original);
        q2.push(cloned);
        
        while(!q1.empty()){
            int sz = q1.size();
            while(sz--){
                TreeNode* p1 = q1.front();q1.pop();
                TreeNode* p2 = q2.front();q2.pop();
                if(p1->left){
                    if(p1->left == target) return p2->left;
                    q1.push(p1->left);
                    q2.push(p2->left);
                }
                if(p1->right){
                    if(p1->right == target) return p2->right;
                    q1.push(p1->right);
                    q2.push(p2->right);
                }
            }
        }
        return NULL;
    }
};