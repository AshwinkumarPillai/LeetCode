// ITERATIVE SOLUTION
class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ans = {{}};

        for (int x : nums)
        {
            int sz = ans.size();
            for (int i = 0; i < sz; i++)
            {
                vector<int> sub = ans[i];
                sub.push_back(x);
                ans.push_back(sub);
            }
        }

        return ans;
    }
};

// NORMAL DFS
class Solution
{
public:
    void dfs(vector<vector<int>> &ans, vector<int> &cur, vector<int> &nums, int i, int &n)
    {
        if (i == n)
        {
            ans.push_back(cur);
            return;
        }
        cur.push_back(nums[i]);
        dfs(ans, cur, nums, i + 1, n);
        cur.pop_back();
        dfs(ans, cur, nums, i + 1, n);
    }

    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> curr;
        int n = nums.size();
        dfs(ans, curr, nums, 0, n);
        return ans;
    }
};

// Lexicographic (Binary Sorted) Subsets

class Solution
{
public:
    vector<int> FindSubSet(int no, vector<int> &nums)
    {
        vector<int> re;
        int i = 0;
        while (no)
        {
            if (no & 1)
            {
                re.push_back(nums[i]);
            }
            i++;
            no >>= 1;
        }
        return re;
    }
    vector<vector<int>> subsets(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> ans;
        int total = 1 << n;
        for (int i = 0; i < total; i++)
        {
            vector<int> temp = FindSubSet(i, nums);
            ans.push_back(temp);
        }
        return ans;
    }
};

// BackTracking Solution

class Solution
{
public:
    void bt(vector<int> &nums, int start, int i, int n, vector<vector<int>> &ans, vector<int> &state)
    {
        if (state.size() == i)
            ans.push_back(state);

        for (int j = start; j < n; j++)
        {
            state.push_back(nums[j]);
            bt(nums, j + 1, i, n, ans, state);
            state.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int> &nums)
    {
        int n = nums.size();
        if (!n)
            return {};
        vector<vector<int>> ans;
        for (int i = 0; i <= n; i++)
        {
            vector<int> state;
            bt(nums, 0, i, n, ans, state);
        }
        return ans;
    }
};

// Cascading Solution
class Solution
{
public:
    void fillPowerSet(vector<int> &nums, int i, int n, vector<vector<int>> &ans)
    {
        if (i >= n)
            return;
        int v = nums[i];
        vector<vector<int>> t = ans;
        for (auto x : t)
        {
            x.push_back(v);
            ans.push_back(x);
        }
        fillPowerSet(nums, i + 1, n, ans);
    }

    vector<vector<int>> subsets(vector<int> &nums)
    {
        int i = 0, n = nums.size();
        if (n == 0)
            return {};
        vector<vector<int>> ans;
        ans.push_back({});
        fillPowerSet(nums, i, n, ans);
        return ans;
    }
};