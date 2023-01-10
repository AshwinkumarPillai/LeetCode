// DFS
class Solution
{
public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (!p || !q)
            return p == q;
        if (p->val != q->val)
            return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

// BFS
class Solution
{
public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (!p || !q)
            return p == q;
        if (p->val != q->val)
            return false;
        queue<pair<TreeNode *, TreeNode *>> qu;
        qu.push({p, q});
        while (!qu.empty())
        {
            int sz = qu.size();
            while (sz--)
            {
                auto pu = qu.front();
                qu.pop();
                if ((!pu.first || !pu.second) && (pu.first != pu.second))
                    return false;
                if (!pu.first && !pu.second)
                    continue;
                if (pu.first->val != pu.second->val)
                    return false;
                qu.push({pu.first->left, pu.second->left});
                qu.push({pu.first->right, pu.second->right});
            }
        }
        return true;
    }
};