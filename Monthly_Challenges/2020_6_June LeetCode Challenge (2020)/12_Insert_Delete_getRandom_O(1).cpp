class RandomizedSet
{
public:
    /** Initialize your data structure here. */
    map<int, int> m;
    vector<int> vals;
    int n = 0;
    RandomizedSet()
    {
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val)
    {
        if (n == 0)
        {
            m[val] = 0;
            vals.emplace_back(val);
            n++;
            return true;
        }
        else if (m.find(val) != m.end())
        {
            return false;
        }
        m[val] = n;
        n++;
        vals.emplace_back(val);
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val)
    {
        auto it = m.find(val);
        if (it == m.end())
        {
            return false;
        }
        int index = m[val];
        int lastval = vals[n - 1];
        vals[index] = lastval;
        m[lastval] = index;
        vals.pop_back();
        m.erase(val);
        n--;
        return true;
    }

    /** Get a random element from the set. */
    int getRandom()
    {
        int r = rand() % n;
        return vals[r];
    }
};
