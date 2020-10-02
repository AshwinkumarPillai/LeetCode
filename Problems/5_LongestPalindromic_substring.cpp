class Solution
{
public:
    int expand(string &s, int l, int r)
    {
        int n = s.length();
        if ((s == "") || l > r)
        {
            return 0;
        }
        while ((l >= 0) && (r < n) && (s[l] == s[r]))
        {
            l--;
            r++;
        }
        return (r - l - 1);
    }

    string longestPalindrome(string s)
    {
        int n = s.length();
        if (n == 1)
        {
            return s;
        }

        int low = 0;
        int high = 0;
        int best = 0;

        for (int i = 0; i < n; i++)
        {
            int l1 = expand(s, i, i);
            int l2 = expand(s, i, i + 1);
            int len = max(l1, l2);
            if (len > best)
            {
                best = len;
                low = i - ((len - 1) / 2);
                high = i + len / 2;
            }
        }

        return s.substr(low, best);
    }
};