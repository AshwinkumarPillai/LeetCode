class Solution
{

public:
    string removeKdigits(string num, int k)
    {
        int n = num.length();
        if (n == k)
        {
            return "0";
        }

        int i = 0;

        while (i < n && k > 0)
        {
            if (i == n)
            {
                num.erase(i, 1);
                i = 0;
                k--;
            }
            else if (num[i + 1] == '0')
            {
                num.erase(i, 1);
                while (num[0] == '0')
                {
                    num.erase(0, 1);
                }
                i = 0;
                k--;
            }
            else
            {
                if (num[i] > num[i + 1])
                {
                    num.erase(i, 1);
                    i = 0;
                    k--;
                }
                else
                {
                    i++;
                }
            }
        }

        if (num == "")
        {
            return "0";
        }
        return num;
    }
};