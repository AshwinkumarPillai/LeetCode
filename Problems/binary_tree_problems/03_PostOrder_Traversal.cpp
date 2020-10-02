class Solution
{
public:
    vector<int> post;
    void dfs(TreeNode *root)
    {
        if (!root)
            return;
        dfs(root->left);
        dfs(root->right);
        post.emplace_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode *root)
    {
        dfs(root);
        return post;
    }
};