class Solution
{
public:
    int depth = 0;
    void dfs(TreeNode *root, int d)
    {
        if (!root)
        {
            return;
        }
        depth = max(depth, d);
        dfs(root->left, d + 1);
        dfs(root->right, d + 1);
    }
    int maxDepth(TreeNode *root)
    {
        dfs(root, 1);
        return depth;
    }
};