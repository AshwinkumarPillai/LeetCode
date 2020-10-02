class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        if (nums.size() == 1)
        {
            return nums[0];
        }
        int n = nums.size();
        unordered_map<int, int> m;

        for (int x : nums)
        {
            if (m.find(x) == m.end())
            {
                m[x] = 1;
            }
            else
            {
                m[x]++;
            }
            if (m[x] > n / 2)
            {
                return x;
            }
        }
        return 0;
    }
};