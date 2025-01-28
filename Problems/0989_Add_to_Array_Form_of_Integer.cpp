class Solution
{
public:
    vector<int> addToArrayForm(vector<int> &num, int k)
    {
        vector<int> ans;
        int i = num.size();
        int val = k;
        while (--i >= 0 || val > 0)
        {
            if (i >= 0)
                val += num[i];
            ans.emplace_back(val % 10);
            val /= 10;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};