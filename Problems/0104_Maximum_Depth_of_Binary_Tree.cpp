// direct
class Solution
{
public:
    int countDepth(TreeNode *root, int depth)
    {
        if (root == NULL)
        {
            return depth;
        }

        return max(countDepth(root->left, depth + 1), countDepth(root->right, depth + 1));
    }

    int maxDepth(TreeNode *root)
    {
        return countDepth(root, 0);
    }
};

// using a global variable
class Solution
{
public:
    int ans = 0;

    void dfs(TreeNode *root, int level)
    {
        if (!root)
            return;
        ans = max(level, ans);
        dfs(root->left, level + 1);
        dfs(root->right, level + 1);
    }

    int maxDepth(TreeNode *root)
    {
        dfs(root, 1);
        return ans;
    }
};