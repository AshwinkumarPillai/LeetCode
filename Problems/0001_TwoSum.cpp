class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int k)
    {
        unordered_map<int, int> m;
        vector<int> res;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int x = nums[i];
            int diff = 0;
            if (x > k)
            {
                diff = -1 * (x - k);
            }
            else
            {
                diff = k - x;
            }
            if (m.find(diff) != m.end())
            {
                res.emplace_back(m[diff]);
                res.emplace_back(i);
                return res;
            }
            if (m.find(x) == m.end())
            {
                m[x] = i;
            }
        }
        return res;
    }
};