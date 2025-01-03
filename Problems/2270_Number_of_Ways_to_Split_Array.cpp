class Solution
{
public:
    int waysToSplitArray(vector<int> &nums)
    {
        int n = nums.size();
        vector<long long> prefix;
        long long currSum = 0;
        for (int x : nums)
        {
            currSum += x;
            prefix.push_back(currSum);
        }
        int ans = 0;
        for (int i = 0; i < n - 1; i++)
        {
            long long left = prefix[i];
            long long right = prefix[n - 1] - prefix[i];
            if (left >= right)
                ans++;
        }

        return ans;
    }
};