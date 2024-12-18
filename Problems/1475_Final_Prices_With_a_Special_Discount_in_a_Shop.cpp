class Solution
{
public:
    vector<int> finalPrices(vector<int> &prices)
    {
        int n = prices.size();

        vector<int> ans;

        for (int i = 0; i < n; i++)
        {
            int curDiscount = 0;
            for (int j = i + 1; j < n; j++)
            {
                if (prices[j] <= prices[i])
                {
                    curDiscount = prices[j];
                    break;
                }
            }
            ans.push_back(prices[i] - curDiscount);
        }
        return ans;
    }
};