class Solution
{
public:
    int dfs(TreeNode *root, int csum)
    {
        if (!root)
            return 0;
        int nsum = csum * 10 + root->val;
        if (!root->left && !root->right)
            return nsum;
        return dfs(root->left, nsum) + dfs(root->right, nsum);
    }

    int sumNumbers(TreeNode *root)
    {
        return dfs(root, 0);
    }
};

// ---------------------------------------------------------------------------
// Space Expensive Solution

class Solution
{
public:
    void dfs(TreeNode *root, vector<int> &v, vector<int> &digits)
    {
        digits.push_back(root->val);
        if (root->left == NULL && root->right == NULL)
        {
            string s = "";
            for (int x : digits)
            {
                s += to_string(x);
            }
            v.push_back(stoi(s));
            digits.pop_back();
            return;
        }
        if (root->left == NULL)
        {
            dfs(root->right, v, digits);
            digits.pop_back();
            return;
        }
        if (root->right == NULL)
        {
            dfs(root->left, v, digits);
            digits.pop_back();
            return;
        }
        dfs(root->left, v, digits);
        dfs(root->right, v, digits);
        digits.pop_back();
    }

    int sumNumbers(TreeNode *root)
    {
        if (!root)
            return 0;
        vector<int> v;
        vector<int> d;
        dfs(root, v, d);
        int ans = 0;
        for (int x : v)
        {
            ans += x;
        }
        return ans;
    }
};