// Array Solution - Initial
class Solution
{
public:
    void TravNodes(Node *head, vector<Node *> &ans)
    {
        ans.push_back(head);
        if (head->child)
            TravNodes(head->child, ans);
        if (!head->next)
            return;
        TravNodes(head->next, ans);
    }

    Node *flatten(Node *head)
    {
        if (!head)
            return head;
        vector<Node *> ans;
        ans.push_back(NULL);
        TravNodes(head, ans);
        for (int i = 1; i < ans.size() - 1; i++)
        {
            ans[i]->prev = ans[i - 1];
            ans[i]->next = ans[i + 1];
            ans[i]->child = nullptr;
        }
        ans[ans.size() - 1]->prev = ans[ans.size() - 2];
        ans[ans.size() - 1]->next = NULL;
        ans[ans.size() - 1]->child = NULL;
        return ans[1];
    }
};

// Recursive Solution - No extra space

class Solution
{
public:
    Node *flatten(Node *head)
    {
        if (!head)
            return NULL;
        Node *trav = head;
        while (trav)
        {
            if (trav->child)
            {
                Node *next = trav->next;
                Node *child = flatten(trav->child);
                trav->child = NULL;
                trav->next = child;
                child->prev = trav;
                Node *lastNode = child;
                while (lastNode->next)
                    lastNode = lastNode->next;
                lastNode->next = next;
                if (next)
                    next->prev = lastNode;
            }
            trav = trav->next;
        }
        return head;
    }
};