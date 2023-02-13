class Solution
{
public:
    int countOdds(int low, int high)
    {
        return (high + 1) / 2 - (low / 2);
    }
};

class Solution
{
public:
    int countOdds(int low, int high)
    {
        if (low % 2 == 0)
            low++;
        if (high % 2 == 0)
            high--;
        // high = low + (n - 1) * 2; (T = a + (n-1)* d)
        return (high - low) / 2 + 1;
    }
};

class Solution
{
public:
    int countOdds(int low, int high)
    {
        int x = (high - low) / 2;
        if (((high & 1) == 0) && ((low & 1) == 0))
            return x;
        return x + 1;
    }
};