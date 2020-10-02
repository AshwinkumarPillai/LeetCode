// Using bit-masking
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int countBits, ans = 0;
        for (int i = 0; i < 32; i++)
        {
            countBits = 0;
            for (int j : nums)
            {
                countBits += ((1 << i) & j) ? 1 : 0;
            }
            if (countBits % 3)
            {
                ans |= (1 << i);
            }
        }
        return ans;
    }
}

// Using map
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        map<int, int> m;
        for (int x : nums)
            m[x]++;
        for (auto p : m)
        {
            if (p.second == 1)
                return p.first;
        }
        return -1;
    }
};