class Solution
{
public:
    int postIndex;
    TreeNode *bthelper(vector<int> &post, vector<int> &in, int i, int j)
    {
        if (i > j)
        {
            return NULL;
        }
        int val = post[postIndex--];
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
        root->right = bthelper(post, in, index + 1, j);
        root->left = bthelper(post, in, i, index - 1);
        return root;
    }
    TreeNode *buildTree(vector<int> &in, vector<int> &post)
    {
        postIndex = post.size() - 1;
        TreeNode *root = bthelper(post, in, 0, (int)in.size() - 1);
        return root;
    }
};