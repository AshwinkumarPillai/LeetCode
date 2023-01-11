class Solution
{
public:
    vector<int> pre;
    void dfs(TreeNode *root)
    {
        if (!root)
            return;
        pre.emplace_back(root->val);
        dfs(root->left);
        dfs(root->right);
    }
    vector<int> preorderTraversal(TreeNode *root)
    {
        dfs(root);
        return pre;
    }
};