class Solution
{
public:
    int firstBadVersion(int n)
    {

        int low = 1;
        int high = n;
        int mid = 0;

        while (low <= high)
        {
            mid = low + (high - low) / 2;
            bool x = isBadVersion(mid);
            if (x)
            {
                if (!isBadVersion(mid - 1))
                {
                    return mid;
                }
                else
                {
                    high = mid - 1;
                }
            }
            else
            {
                if (isBadVersion(mid + 1))
                {
                    return (mid + 1);
                }
                else
                {
                    low = mid + 1;
                }
            }
        }
        return -1;
    }
};