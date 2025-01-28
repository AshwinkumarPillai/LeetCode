// Math Solution
class Solution
{
public:
    int arrangeCoins(int n)
    {
        return int(sqrt(2 * (long)n + 0.25) - 0.5);
    }
};

// Binary Search Solution
class Solution
{
public:
    int arrangeCoins(int n)
    {
        long low = 0, high = n;
        long mid, currTotal;
        while (low <= high)
        {
            mid = low + (high - low) / 2;
            currTotal = mid * (mid + 1) / 2;
            if (currTotal == n)
                return (int)mid;
            if (currTotal > n)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return (int)high;
    }
};