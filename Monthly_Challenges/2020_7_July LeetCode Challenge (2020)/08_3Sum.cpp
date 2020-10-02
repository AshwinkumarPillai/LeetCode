class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &arr)
    {
        int k = 0;
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        set<vector<int>> s;
        int n = arr.size();
        for (int i = 0; i < n - 2; i++)
        {
            int val = arr[i];
            int l = i + 1;
            int r = n - 1;
            while (l < r)
            {
                int csum = val + arr[l] + arr[r];
                if (csum == k)
                {
                    s.insert({val, arr[l++], arr[r--]});
                }
                else if (csum < k)
                {
                    l++;
                }
                else
                {
                    r--;
                }
            }
        }
        for (auto x : s)
        {
            ans.push_back(x);
        }
        return ans;
    }
};