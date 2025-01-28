//Without extra space (only recursion)
class Solution {
public:
    
    int ans;
    
    int dfs(TreeNode* root, int k){
        if(!root) return k;
        k = dfs(root->left, k);
        k--;
        if(k == 0) ans = root->val;
        k = dfs(root->right, k);
        return k;
    }
    
    int kthSmallest(TreeNode* root, int k) {
        dfs(root, k);
        return ans;
    }
};

// Using stack | Optimized Space solution with respect to array -> O(height + k)
class Solution
{
public: 
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
};


// Using array
class Solution {
public:
    
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