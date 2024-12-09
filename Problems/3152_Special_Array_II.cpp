class Solution
{
public:
    vector<bool> isArraySpecial(vector<int> &nums, vector<vector<int>> &queries)
    {
        int parity = (nums[0] & 1) == 1 ? 0 : 1; // 1 - odd, 0 - even
        int setNum = 0, n = nums.size();
        map<int, int> m;

        for (int i = 0; i < n; i++)
        {
            int p = nums[i] & 1;
            if (p == parity)
                setNum++;
            else
                parity = p;
            m[i] = setNum;
        }

        vector<bool> ans;

        for (vector<int> query : queries)
        {
            ans.push_back(m[query[0]] == m[query[1]]);
        }

        return ans;
    }
};