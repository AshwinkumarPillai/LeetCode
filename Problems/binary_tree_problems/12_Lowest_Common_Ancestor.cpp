/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    TreeNode *ans;
    bool lca(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == NULL)
        {
            return false;
        }
        if (root == p || root == q)
        {
            bool v1 = lca(root->left, p, q);
            bool v2 = lca(root->right, p, q);
            if (v1 || v2)
            {
                ans = root;
                return false;
            }
            return true;
        }

        bool v1 = lca(root->left, p, q);
        bool v2 = lca(root->right, p, q);

        if (v1 && v2)
        {
            ans = root;
            return false;
        }

        return (v1 || v2);
    }
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        lca(root, p, q);
        return ans;
    }
};