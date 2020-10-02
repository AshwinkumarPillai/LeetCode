class Solution
{
public:
    pair<int, TreeNode *> dfs(TreeNode *root, int val, int depth, TreeNode *parent)
    {

        if (root->val == val)
        {
            return {depth, parent};
        }

        if (root->right == NULL && root->left == NULL)
        {
            return {-1, NULL};
        }
        else
        {
            if (root->right == NULL)
            {
                return dfs(root->left, val, depth + 1, root);
            }
            else if (root->left == NULL)
            {
                return dfs(root->right, val, depth + 1, root);
            }
            else
            {
                pair<int, TreeNode *> l = dfs(root->left, val, depth + 1, root);
                pair<int, TreeNode *> r = dfs(root->right, val, depth + 1, root);
                if (l.first == -1 && r.first == -1)
                {
                    return {-1, NULL};
                }
                else
                {
                    if (l.first != -1)
                    {
                        return l;
                    }
                    else
                    {
                        return r;
                    }
                }
            }
        }
    }

    bool isCousins(TreeNode *root, int x, int y)
    {
        pair<int, TreeNode *> p = dfs(root, x, 0, NULL);
        pair<int, TreeNode *> q = dfs(root, y, 0, NULL);
        if (p.first == -1 || q.first == -1)
        {
            return false;
        }
        if (p.first != q.first)
        {
            return false;
        }
        if (p.second == q.second)
        {
            return false;
        }
        return true;
    }
};