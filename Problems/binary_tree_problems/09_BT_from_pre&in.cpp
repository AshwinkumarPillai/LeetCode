class Solution
{
public:
    int preIndex = 0;
    TreeNode *bthelper(vector<int> &pre, vector<int> &in, int i, int j)
    {
        if (i > j)
        {
            return NULL;
        }
        int val = pre[preIndex++];
        TreeNode *root = new TreeNode(val);
        if (i == j)
        {
            return root;
        }
        int index = i;
        while (index <= j)
        {
            if (in[index] == val)
            {
                break;
            }
            index++;
        }
        root->left = bthelper(pre, in, i, index - 1);
        root->right = bthelper(pre, in, index + 1, j);
        return root;
    }
    TreeNode *buildTree(vector<int> &pre, vector<int> &in)
    {
        TreeNode *root = bthelper(pre, in, 0, (int)in.size() - 1);
        return root;
    }
};