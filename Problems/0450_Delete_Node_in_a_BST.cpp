class Solution {
public:
    TreeNode* leftMostChild(TreeNode* root) {
        if (!root || !root->left) return root;
        return leftMostChild(root->left);
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;
        if (key < root->val) root->left = deleteNode(root->left, key);
        else if (key > root->val) root->right = deleteNode(root->right, key);
        else {
            if (!root->left || !root->right) {
                TreeNode* toDelete = root;
                root = root->left ? root->left : root->right;
                delete toDelete;
            }
            else {
                TreeNode* leftmost = leftMostChild(root->right);
                root->val = leftmost->val;
                root->right = deleteNode(root->right, leftmost->val);
            }
        }
        return root;
    }
};
