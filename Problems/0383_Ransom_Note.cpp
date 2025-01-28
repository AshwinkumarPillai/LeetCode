class Solution
{
public:
    bool canConstruct(string r, string magazine)
    {
        unordered_map<char, int> m;
        for (char x : magazine)
        {
            if (m.find(x) != m.end())
            {
                m[x]++;
            }
            else
            {
                m[x] = 1;
            }
        }

        for (char x : r)
        {
            if (m.find(x) == m.end())
            {
                return false;
            }
            else
            {
                m[x]--;
                if (m[x] == 0)
                {
                    m.erase(m.find(x));
                }
            }
        }
        return true;
    }
};