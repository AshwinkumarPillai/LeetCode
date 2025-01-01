class Solution
{
public:
    int maxScore(string s)
    {
        int right = 0;
        for (char x : s)
        {
            if (x == '1')
                right++;
        }

        int ans = 0, left = 0, n = s.length();

        for (int i = 0; i < n - 1; i++)
        {
            if (s[i] == '0')
                left++;
            else
                right--;
            ans = max(ans, left + right);
        }

        return ans;
    }
};