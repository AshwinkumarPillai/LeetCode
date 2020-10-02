class Solution
{
public:
    int widthOfBinaryTree(TreeNode *root)
    {
        if (!root)
            return 0;
        queue<pair<TreeNode *, int>> q;
        q.push({root, 1});
        int ans = 1;
        while (!q.empty())
        {
            int sz = q.size();
            int minval = INT_MAX, maxval = 0;
            while (sz--)
            {
                auto node = q.front();
                q.pop();
                int x = node.second * 2;
                if (node.first->left)
                {
                    q.push({node.first->left, x});
                    minval = min(minval, x);
                    maxval = max(maxval, x);
                }
                if (node.first->right)
                {
                    q.push({node.first->right, x - 1});
                    minval = min(minval, x - 1);
                    maxval = max(maxval, x - 1);
                }
            }
            minval = (minval == INT_MAX) ? 0 : minval;
            ans = max((maxval - minval + 1), ans);
        }
        return ans;
    }
};