class Solution
{
public:
    int myAtoi(string s)
    {
        int i = 0, n = s.length();
        if (n == 0)
        {
            return 0;
        }
        while (s[i] == ' ')
        {
            i++;
            if (i == n)
            {
                break;
            }
        }
        if (i == n)
        {
            return 0;
        }
        long ans = 0;
        bool isneg = false;
        if (s[i] == '-')
        {
            isneg = true;
            i++;
        }
        if (s[i] == '+')
        {
            if (isneg)
            {
                return 0;
            }
            i++;
        }
        int val = (int)s[i];
        if (val < 48 || val > 57)
        {
            return 0;
        }
        while (i < n - 1 && (val >= 48 && val <= 57))
        {
            if (ans >= INT_MAX)
            {
                if (isneg)
                {
                    return INT_MIN;
                }
                return INT_MAX;
            }
            ans = ans * 10 + (val - 48);
            val = s[++i];
        }
        if (val >= 48 && val <= 57)
        {
            ans = ans * 10 + (val - 48);
        }
        if (isneg)
        {
            ans *= -1;
        }
        if (ans > INT_MAX)
        {
            return INT_MAX;
        }
        if (ans < INT_MIN)
        {
            return INT_MIN;
        }
        return ans;
    }
};