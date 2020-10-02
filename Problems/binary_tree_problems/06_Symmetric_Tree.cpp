class Solution
{
public:
    bool checkMirror(TreeNode *n1, TreeNode *n2)
    {
        //Leaf Node
        if (n1 == NULL && n2 == NULL)
        {
            return true;
        }
        //Has only one child so not symmetric
        if (n1 == NULL || n2 == NULL)
        {
            return false;
        }

        // Both node have same value and their opposite chiildren are same
        return (n1->val == n2->val) && checkMirror(n1->left, n2->right) && checkMirror(n1->right, n2->left);
    }

    bool isSymmetric(TreeNode *root)
    {
        return checkMirror(root, root);
    }
};