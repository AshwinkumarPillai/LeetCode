class Solution
{
public:
    vector<int> prisonAfterNDays(vector<int> &cells, int N)
    {
        N = N % 14 == 0 ? 14 : N % 14; // Pattern repeats after 14 days
        vector<int> ans(8);
        while (N > 0)
        {
            for (int i = 1; i < cells.size() - 1; i++)
                ans[i] = cells[i - 1] == cells[i + 1] ? 1 : 0;
            cells = ans;
            N--;
        }

        return cells;
    }
};