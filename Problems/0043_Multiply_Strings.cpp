class Solution
{
public:
    string multiply(string num1, string num2)
    {
        if (num1 == "0" || num2 == "0")
            return "0";
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int m = num1.size(), n = num2.size();

        vector<int> ans(m + n);

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int val = (num1[i] - '0') * (num2[j] - '0');
                ans[i + j] += val;
                ans[i + j + 1] += (ans[i + j] / 10);
                ans[i + j] = ans[i + j] % 10;
            }
        }

        while (ans.back() == 0)
            ans.pop_back();
        string fans = "";
        while (ans.size())
        {
            fans += to_string(ans.back());
            ans.pop_back();
        }

        return fans;
    }
};