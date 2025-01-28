//O(n) solution
class Solution
{
public:
    int thirdMax(vector<int> &nums)
    {
        int n = nums.size();
        long max = nums[0];
        long smax = INT_MIN;
        long tmax = INT_MIN;
        smax--;
        tmax--;
        for (int i = 1; i < n; i++)
        {
            int x = nums[i];
            if (x == max || x == smax || x == tmax)
                continue;
            if (x > max)
            {
                tmax = smax;
                smax = max;
                max = nums[i];
            }
            else if (x > smax)
            {
                tmax = smax;
                smax = nums[i];
            }
            else if (x > tmax)
            {
                tmax = x;
            }
        }
        return (tmax != ((long)INT_MIN - 1)) ? tmax : max;
    }
};

// nlogn solution
class Solution
{
public:
    int thirdMax(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int j = 1;
        int curr = nums[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            if (nums[i] != curr)
            {
                j++;
                curr = nums[i];
                if (j == 3)
                {
                    return nums[i];
                }
            }
        }
        return nums[n - 1];
    }
};