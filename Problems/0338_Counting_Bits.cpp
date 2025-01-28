class Solution
{
public:
    vector<int> countBits(int num)
    {
        vector<int> ans(num + 1);

        //Using dynamic programming
        ans[0] = 0;
        if (num > 0)
        {
            ans[1] = 1;
        }

        for (int i = 2; i <= num; i++)
        {
            ans[i] = ans[i & (i - 1)] + 1;
        }

        return ans;

        // Iterating only for the number of 1's in a number
        // for (int i = 0; i <= num; i++)
        // {
        //     int n = i;
        //     int count = 0;
        //     while (n != 0)
        //     {
        //         n = n & (n - 1);
        //         count++;
        //     }
        //     ans[i] = count;
        // }
    }
};