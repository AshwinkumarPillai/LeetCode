/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// 01 - Recursive DFS
class Solution
{
public:
    bool flipEquiv(TreeNode *root1, TreeNode *root2)
    {
        if (!root1 || !root2)
            return root1 == root2;

        return (root1->val == root2->val) && ((flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right)) || (flipEquiv(root1->right, root2->left) && flipEquiv(root1->left, root2->right)));
    }
};

// 02 - Iterative DFS
class Solution
{
public:
    bool isEqual(TreeNode *r1, TreeNode *r2)
    {
        if (!r1 || !r2)
            return r1 == r2;
        return r1->val == r2->val;
    }

    bool flipEquiv(TreeNode *root1, TreeNode *root2)
    {
        stack<pair<TreeNode *, TreeNode *>> st;
        st.push({root1, root2});

        while (!st.empty())
        {
            pair<TreeNode *, TreeNode *> p = st.top();
            st.pop();
            TreeNode *r1 = p.first, *r2 = p.second;

            if (!isEqual(r1, r2))
                return false;

            if (r1 && r2)
            {
                if (isEqual(r1->left, r2->left) && isEqual(r1->right, r2->right))
                {
                    st.push({r1->left, r2->left});
                    st.push({r1->right, r2->right});
                }
                else if (isEqual(r1->left, r2->right) && isEqual(r1->right, r2->left))
                {
                    st.push({r1->left, r2->right});
                    st.push({r1->right, r2->left});
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
};

// 03 - BFS
