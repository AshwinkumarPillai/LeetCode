// Iterative
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* trav = root;
        
        while(trav){
            int x = trav->val;
            if(x == val) return trav;
            else if(val > x) trav = trav->right;
            else trav = trav->left;
        }
        return NULL;
    }
};

// Recursive
class Solution {
public:
    TreeNode *searchBST(TreeNode *root, int val)
    {
        if (root == NULL)
        {
            return NULL;
        }
        if (root->val == val)
        {
            return root;
        }
        if (root->val < val)
        {
            return searchBST(root->right, val);
        }
        return searchBST(root->left, val);
    }
};