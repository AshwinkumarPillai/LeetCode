class Solution
{
public:
    string convert(string s, int nr)
    {
        string ans = "";
        if (nr == 1)
        {
            return s;
        }
        int n = s.length(), index = 1;
        bool flag = false;
        if (n == 1)
        {
            return s;
        }
        vector<char> pat[nr];
        for (int i = 0; i < n; i++)
        {
            pat[index].emplace_back(s[i]);
            if (flag == nr - 1 or (index == 0 && i != 0))
            {
                flag = !flag;
            }
            if (flag)
            {
                index++;
            }
            else
            {
                index--;
            }
        }

        for (int i = 0; i < nr; i++)
        {
            for (int j = 0; j < (int)pat[i].size(); j++)
            {
                ans += pat[i][j];
            }
        }

        return ans;
    }
};