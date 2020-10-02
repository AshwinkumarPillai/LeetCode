class Codec
{
public:
    void gens(TreeNode *root, string &s)
    {
        if (!root)
        {
            s += "x|";
            return;
        }
        s += to_string(root->val);
        s += '|';
        gens(root->left, s);
        gens(root->right, s);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        string s = "";
        gens(root, s);
        return s;
    }

    int index = 0;
    TreeNode *bt(string data)
    {
        if (index >= data.length() || data[index] == 'x')
        {
            index += 2;
            return NULL;
        }

        int isNeg = 0;
        if (data[index] == '-')
        {
            isNeg = 1;
            index++;
        }

        string temp = "";
        while (data[index] != '|')
        {
            temp += data[index++];
        }
        index++;
        int val = stoi(temp);
        if (isNeg)
            val *= -1;
        TreeNode *root = new TreeNode(val);
        root->left = bt(data);
        root->right = bt(data);
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        TreeNode *root = bt(data);
        return root;
    }
};
