class Solution
{
public:
    bool checkRecord(string s)
    {
        int a = 0, l = 0;
        for (char x : s)
        {
            if (x == 'A')
            {
                if (++a == 2)
                    return false;
                l = 0;
            }
            else if (x == 'L')
            {
                if (++l == 3)
                    return false;
            }
            else
            {
                l = 0;
            }
        }
        return true;
    }
};