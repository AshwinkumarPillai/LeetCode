class Solution
{
public:
    // Optimized solution -> O(height + k)
    int kthSmallest(TreeNode *root, int k)
    {
        stack<TreeNode *> s;
        while (true)
        {
            while (root != NULL)
            {
                s.push(root);
                root = root->left;
            }
            root = s.top();
            s.pop();
            if (--k == 0)
            {
                return root->val;
            }
            root = root->right;
        }
    }

    // O(n) solution
    vector<int> trav;

    void dfs(TreeNode *root)
    {
        if (root == NULL)
        {
            return;
        }
        dfs(root->left);
        trav.emplace_back(root->val);
        dfs(root->right);
    }

    int kthSmallest(TreeNode *root, int k)
    {
        dfs(root);
        return trav[k - 1];
    }
};