class Solution
{
public:
    static bool comp(pair<char, int> &p1, pair<char, int> &p2)
    {
        return p1.second > p2.second;
    }
    string frequencySort(string s)
    {
        unordered_map<char, int> m;

        for (char x : s)
        {
            m[x]++;
        }
        vector<pair<char, int>> v;
        for (auto x : m)
        {
            v.push_back({x.first, x.second});
        }
        sort(v.begin(), v.end(), comp);
        string ans = "";
        for (auto x : v)
        {
            while (x.second--)
            {
                ans += x.first;
            }
        }
        return ans;
    }
};