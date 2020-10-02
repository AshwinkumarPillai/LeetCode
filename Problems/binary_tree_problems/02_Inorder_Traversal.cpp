class Solution
{
public:
    vector<int> in;
    void dfs(TreeNode *root)
    {
        if (!root)
            return;
        dfs(root->left);
        in.emplace_back(root->val);
        dfs(root->right);
    }
    vector<int> inorderTraversal(TreeNode *root)
    {
        dfs(root);
        return in;
    }
};