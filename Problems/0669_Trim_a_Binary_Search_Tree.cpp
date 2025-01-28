// Simple Recursion
class Solution {
public:
    
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(!root) return root;
        if(root->val > high) return trimBST(root->left, low, high);
        if(root->val < low) return trimBST(root->right, low, high);
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        return root;
    }
};


// Overkill Code
class Solution {
public:
    
    TreeNode* getLeftNode(TreeNode* root, int low, int high){
        if(!root->right) return NULL;
        if(root->right->val < low) return getLeftNode(root->right, low, high);
        if(root->right->val > high) return getRightNode(root->right, low, high);
        return root->right;
    }
    
    TreeNode* getRightNode(TreeNode* root,int low, int high){
        if(!root->left) return NULL;
        if(root->left->val > high) return getRightNode(root->left, low, high);
        if(root->left->val < low) return getLeftNode(root->left, low, high);
        return root->left;
    }
    
    void checkNode(TreeNode* root, int low, int high){
        if(!root) return;
        if(root->val == low) root->left = NULL;
        else if(root->left && root->left->val < low){
            root->left = getLeftNode(root->left, low, high);
        }
        
        if(root->val == high) root->right = NULL;
        else if(root->right && root->right->val > high){
            root->right = getRightNode(root->right, low, high);
        }
        
        checkNode(root->left, low, high);
        checkNode(root->right, low, high);
    }
    
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        TreeNode* head = root;
        if(root->val < low) head = getLeftNode(root, low, high);
        else if(root->val > high) head = getRightNode(root, low, high);
        checkNode(head, low, high);
        return head;
    }
};