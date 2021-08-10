// DFS
class Solution {
public:
    
    pair<int, bool> checkSubtreeDepth(TreeNode* root){
        if(!root) return {0, true};
        auto left = checkSubtreeDepth(root->left);
        auto right = checkSubtreeDepth(root->right);
        if(!left.second || !right.second) return {-1, false};
        if(abs(left.first - right.first) > 1) return {-1, false};
        return {max(left.first, right.first) + 1, true};
    }
    
    bool isBalanced(TreeNode* root) {
        return checkSubtreeDepth(root).second;
    }
};
