class Solution
{
public:
    void dfs(vector<vector<int>> &ans, vector<int> &curr, vector<int> &nums, int i, int &target, int &n, int curSum)
    {
        if (curSum > target || i == n)
            return;
        if (curSum == target)
        {
            ans.push_back(curr);
            return;
        }

        curr.push_back(nums[i]);
        dfs(ans, curr, nums, i, target, n, curSum + nums[i]);
        curr.pop_back();
        dfs(ans, curr, nums, i + 1, target, n, curSum);
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> curr;
        int n = candidates.size();
        dfs(ans, curr, candidates, 0, target, n, 0);
        return ans;
    }
};