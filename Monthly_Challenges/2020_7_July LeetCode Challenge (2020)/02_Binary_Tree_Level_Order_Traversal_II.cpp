class Solution
{
public:
    void dfs(TreeNode *root, int level, vector<vector<int>> &ans)
    {
        if (!root)
            return;
        if (level == ans.size())
            ans.push_back({});
        ans[level].push_back(root->val);
        dfs(root->left, level + 1, ans);
        dfs(root->right, level + 1, ans);
    }

    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        if (!root)
            return {};
        vector<vector<int>> ans;
        dfs(root, 0, ans);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};