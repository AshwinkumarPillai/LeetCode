class Solution
{
public:
    void ripple(int &ans, string &s, int i, int j, int n)
    {
        if (s[i] != s[j])
            return;
        ans += 1;
        while (i - 1 >= 0 && j + 1 < n && s[i - 1] == s[j + 1])
        {
            i--;
            j++;
            ans += 1;
        }
    }

    int countSubstrings(string s)
    {
        int n = s.length();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ripple(ans, s, i, i, n);
            ripple(ans, s, i, i + 1, n);
        }
        return ans;
    }
};