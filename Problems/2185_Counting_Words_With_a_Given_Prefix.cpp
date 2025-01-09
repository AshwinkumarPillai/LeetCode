// Brute Force with pointer
class Solution
{
public:
    int prefixCount(vector<string> &words, string pref)
    {
        int ans = 0, n = pref.size();

        for (string &word : words)
        {
            for (int i = 0; i < n; i++)
            {
                if (pref[i] != word[i])
                    break;
                if (i == n - 1)
                    ans += 1;
            }
        }
        return ans;
    }
};

// Less memory - don't save size in variable n
class Solution
{
public:
    int prefixCount(vector<string> &words, string pref)
    {
        int ans = 0;

        for (string &word : words)
        {
            int i;
            for (i = 0; i < pref.size(); i++)
            {
                if (pref[i] != word[i])
                    break;
            }
            if (i == pref.size())
                ans += 1;
        }
        return ans;
    }
};

// Built-in method
class Solution
{
public:
    int prefixCount(vector<string> &words, string pref)
    {
        int ans = 0;

        for (string &word : words)
        {
            if (word.find(pref) == 0)
                ans++;
        }
        return ans;
    }
};