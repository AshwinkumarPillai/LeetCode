// RIPPLE SOLUTION
class Solution
{
public:
    string ripple(string &s, int i, int j, int n)
    {
        if (s[i] != s[j])
            return "";
        while (i - 1 >= 0 && j + 1 < n && s[i - 1] == s[j + 1])
        {
            i--;
            j++;
        }
        return s.substr(i, j - i + 1);
    }

    string longestPalindrome(string s)
    {
        string ans = "";
        int n = s.length();
        for (int i = 0; i < n; i++)
        {
            string a = ripple(s, i, i, n);
            string b = ripple(s, i, i + 1, n);
            string t = a.length() > b.length() ? a : b;
            if (t.length() > ans.length())
                ans = t;
        }
        return ans;
    }
};

// WITHOUT STORING THE STRINGS
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