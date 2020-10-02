class Trie
{
private:
    class Node
    {
    public:
        unordered_map<char, Node *> children;
        bool isend;
        Node()
        {
            isend = false;
        }
    };

public:
    Node *root = NULL;

    Trie() {}

    void insert(string word)
    {
        if (root == NULL)
        {
            root = new Node();
            Node *node = root;
            for (char s : word)
            {
                Node *child = new Node();
                node->children[s] = child;
                node = child;
            }
            node->isend = true;
        }
        else
        {
            Node *node = root;
            for (char s : word)
            {
                if (node->children.find(s) == node->children.end())
                {
                    Node *child = new Node();
                    node->children[s] = child;
                    node = child;
                }
                else
                {
                    Node *child = node->children[s];
                    node = child;
                }
            }
            node->isend = true;
        }
    }

    bool search(string word)
    {
        if (root == NULL)
        {
            return false;
        }
        Node *node = root;
        for (char s : word)
        {
            if (node->children.find(s) == node->children.end())
            {
                return false;
            }
            Node *child = node->children[s];
            node = child;
        }
        if (node->isend)
        {
            return true;
        }
        return false;
    }

    bool startsWith(string prefix)
    {
        if (root == NULL)
        {
            return false;
        }
        Node *node = root;
        for (char s : prefix)
        {
            if (node->children.find(s) == node->children.end())
            {
                return false;
            }
            Node *child = node->children[s];
            node = child;
        }
        return true;
    }
};