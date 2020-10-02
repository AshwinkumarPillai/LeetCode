// The java solution contains proper seperate chaining implementation
class MyHashSet
{
public:
    vector<int> hashSet;
    MyHashSet()
    {
        hashSet.resize(1000001);
    }

    void add(int key)
    {
        hashSet[key] = 1;
    }

    void remove(int key)
    {
        hashSet[key] = 0;
    }

    bool contains(int key)
    {
        return hashSet[key];
    }
};
