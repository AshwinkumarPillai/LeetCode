class Solution
{
public:
    int pivotIndex(vector<int> &nums)
    {
        int sum = 0, n = nums.size();
        for (int x : nums)
            sum += x;
        int curr = 0;
        for (int i = 0; i < n; i++)
        {
            if (curr == (sum - curr - nums[i]))
                return i;
            curr += nums[i];
        }
        return -1;
    }
};