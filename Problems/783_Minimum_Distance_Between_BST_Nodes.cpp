class Solution
{
public:
    vector<int> inorder;

    void dfs(TreeNode *root)
    {
        if (!root)
            return;
        dfs(root->left);
        inorder.emplace_back(root->val);
        dfs(root->right);
    }

    int minDiffInBST(TreeNode *root)
    {
        int ans = INT_MAX;
        dfs(root);
        for (int i = inorder.size() - 1; i > 0; i--)
        {
            ans = min(ans, inorder[i] - inorder[i - 1]);
        }
        return ans;
    }
};