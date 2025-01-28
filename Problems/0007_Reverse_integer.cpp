class Solution
{
public:
    int reverse(int x)
    {
        if (x <= INT_MIN)
        {
            return 0;
        }
        bool isneg = false;
        if (x < 0)
        {
            isneg = true;
            x = -x;
        }
        long res = 0;
        while (x > 0)
        {
            res = res * 10 + (x % 10);
            x /= 10;
            if (res > INT_MAX)
            {
                return 0;
            }
        }
        if (isneg)
        {
            res = -res;
        }
        return res;
    }
};