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
class Solution
{
public:
    TreeNode *reverseOddLevels(TreeNode *root)
    {
        queue<TreeNode *> q;
        q.push(root);
        int level = 0;
        while (!q.empty())
        {
            int sz = q.size();
            vector<TreeNode *> currentLevel;

            while (sz--)
            {
                TreeNode *node = q.front();
                q.pop();
                if (level % 2 == 1)
                {
                    currentLevel.push_back(node);
                }
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }

            int left = 0, right = currentLevel.size() - 1;

            while (left <= right)
            {
                int temp = currentLevel[left]->val;
                currentLevel[left]->val = currentLevel[right]->val;
                currentLevel[right]->val = temp;
                left++;
                right--;
            }
            level++;
        }

        return root;
    }
};