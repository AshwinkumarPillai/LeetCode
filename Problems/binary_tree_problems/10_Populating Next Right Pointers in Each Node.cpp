class Solution
{
public:
    Node *connect(Node *root)
    {
        if (!root)
            return root;
        Node *p = root;
        while (p->left)
        {
            Node *c = p;
            while (c)
            {
                c->left->next = c->right;
                if (c->next)
                    c->right->next = c->next->left;
                c = c->next;
            }
            p = p->left;
        }
        return root;
    }
};