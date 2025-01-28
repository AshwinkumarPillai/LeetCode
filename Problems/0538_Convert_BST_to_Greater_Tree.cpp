// Recursion - Reverse Inorder - global sum
class Solution {
public:
    int sum = 0;
    
    TreeNode* convertBST(TreeNode* root) {
        if(!root) return root;
        convertBST(root->right);
        sum += root->val;
        root->val = sum;
        convertBST(root->left);
        return root;
    }
};

// Recursion - Reverse Inorder - with sum as param
class Solution {
public:
    
    int setValue(TreeNode* root, int sum){
        if(!root->right){
            sum += root->val;
            root->val = sum;
            if(root->left) sum = setValue(root->left, sum);
            return sum;
        }
        int val = setValue(root->right, sum);
        root->val = root->val + val;
        sum = root->val;
        if(root->left) sum = setValue(root->left, sum);
        return sum;
    }
    
    TreeNode* convertBST(TreeNode* root) {
        if(!root) return root;
        setValue(root, 0);
        return root;
    }
};

// Iterative - Stack
class Solution {
public:
    
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        TreeNode* trav= root;
        stack<TreeNode*> st;
        
        while(!st.empty() || trav){
            while(trav){
                st.push(trav);
                trav = trav->right;
            }
            
            trav = st.top();st.pop();
            sum += trav->val;
            trav->val = sum;
            trav = trav->left;
        }
        
        return root;
    }
};