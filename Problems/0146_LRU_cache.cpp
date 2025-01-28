// MAP AND DOUBLY LINKED-LIST
class LRUCache
{
public:
    class Node
    {
    public:
        int key;
        int val;
        Node *next;
        Node *prev;

        Node(int key = -1, int val = 0) : key(key), val(val), next(nullptr), prev(nullptr) {}

        void changeVal(int val)
        {
            this->val = val;
        }
    };

    map<int, Node *> m;
    int capacity = 0;
    int size = 0;

    Node *head = NULL;
    Node *tail = NULL;

    LRUCache(int capacity)
    {
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
        this->capacity = capacity;
    }

    ~LRUCache()
    {
        Node *curr = head;
        while (curr)
        {
            Node *nextNode = curr->next;
            delete curr;
            curr = nextNode;
        }
    }

    void resetHead(Node *curr)
    {
        if (curr->prev)
            curr->prev->next = curr->next;
        if (curr->next)
            curr->next->prev = curr->prev;

        curr->next = head->next;
        head->next->prev = curr;

        head->next = curr;
        curr->prev = head;
    }

    void removeLRU_Node()
    {
        Node *lastNode = tail->prev;
        lastNode->prev->next = tail;
        tail->prev = lastNode->prev;
        m.erase(lastNode->key);
        delete lastNode;
        this->size--;
    }

    int get(int key)
    {
        if (m.find(key) == m.end())
            return -1;
        Node *curr = m[key];
        resetHead(curr);

        return m[key]->val;
    }

    void put(int key, int value)
    {
        if (m.find(key) != m.end())
        {
            m[key]->changeVal(value);
            resetHead(m[key]);
            return;
        }
        Node *curr = new Node(key, value);
        m[key] = curr;
        resetHead(curr);
        this->size++;

        if (size > capacity)
            removeLRU_Node();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

// MY OLD CODE
class LRUCache
{
public:
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> m;
    int n = 0;

    LRUCache(int capacity)
    {
        n = capacity;
    }

    int get(int key)
    {
        if (m.find(key) == m.end())
        {
            return -1;
        }
        list<pair<int, int>>::iterator it = m[key];
        pair<int, int> p = *it;
        int val = p.second;
        cache.erase(it);
        cache.push_front({key, val});
        it = cache.begin();
        m[key] = it;
        return val;
    }

    void put(int key, int value)
    {
        bool exist = (m.find(key) != m.end());
        if (n == 0 && !exist)
        {
            list<pair<int, int>>::iterator it = cache.end();
            it--;
            pair<int, int> p = *it;
            m.erase(p.first);
            cache.pop_back();
            n++;
        }
        if (exist)
        {
            list<pair<int, int>>::iterator it = m[key];
            cache.erase(it);
            cache.push_front({key, value});
            it = cache.begin();
            m[key] = it;
        }
        else
        {
            cache.push_front({key, value});
            list<pair<int, int>>::iterator it = cache.begin();
            m[key] = it;
            n--;
        }
    }
};
