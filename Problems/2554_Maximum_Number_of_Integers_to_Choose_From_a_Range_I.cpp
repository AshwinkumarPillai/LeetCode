// USING BITSET
class Solution
{
public:
    int maxCount(vector<int> &banned, int n, int maxSum)
    {
        bitset<10001> ban = 0;
        for (int x : banned)
            ban[x] = 1;

        int ans = 0, sum = 0;

        for (int i = 1; i <= n && sum <= maxSum; i++)
        {
            if (!ban[i])
            {
                sum += i;
                ans++;
            }
        }

        return (sum > maxSum) ? ans - 1 : ans;
    }
};

// USING A SET
class Solution
{
public:
    int maxCount(vector<int> &banned, int n, int maxSum)
    {
        set<int> s;
        for (int x : banned)
            if (x <= n)
                s.insert(x);

        int ans = 0, sum = 0;

        for (int i = 1; i <= n; i++)
        {
            if (s.count(i) == 0)
            {
                if (sum + i > maxSum)
                    return ans;
                sum += i;
                ans++;
            }
        }

        return ans;
    }
};