class Solution
{
public:
    Node *connect(Node *root)
    {
        if (!root)
            return root;
        Node *p = root;
        while (p)
        {
            Node *c = p;
            while (c)
            {
                if (c->left)
                {
                    if (c->right)
                    {
                        c->left->next = c->right;
                    }
                    else if (c->next)
                    {
                        Node *temp = c->next;
                        while (temp)
                        {
                            if (temp->left)
                            {
                                c->left->next = temp->left;
                                break;
                            }
                            else if (temp->right)
                            {
                                c->left->next = temp->right;
                                break;
                            }
                            temp = temp->next;
                        }
                    }
                }
                if (c->right)
                {
                    Node *temp = c->next;
                    while (temp)
                    {
                        if (temp->left)
                        {
                            c->right->next = temp->left;
                            break;
                        }
                        else if (temp->right)
                        {
                            c->right->next = temp->right;
                            break;
                        }
                        temp = temp->next;
                    }
                }
                c = c->next;
            }
            if (p->left)
            {
                p = p->left;
            }
            else if (p->right)
            {
                p = p->right;
            }
            else
            {
                p = p->next;
            }
        }
        return root;
    }
};