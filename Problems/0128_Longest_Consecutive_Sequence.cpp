class Solution {
public:
    int getLowerBound(map<int, bool> &m, int x)
{
    while (m.find(x) != m.end())
    {
        m[x] = false;
        x--;
    }
    return x + 1;
}

int getUpperBound(map<int, bool> &m, int x)
{
    while (m.find(x) != m.end())
    {
        m[x] = false;
        x++;
    }
    return x - 1;
}
    int longestConsecutive(vector<int>& arr) {
        if(arr.size() == 0){
            return 0;
        }
        int ans = 1;
    map<int, bool> m;
    for (int x : arr)
    {
        m[x] = true;
    }

    for (int x : arr)
    {
        if (m[x])
        {
            int l = getLowerBound(m, x);
            int r = getUpperBound(m, x);
            ans = max(ans, r - l + 1);
        }
    }
    return ans;
    }
};