class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int k)
    {
        int r = matrix.size();
        if (r == 0)
            return false;
        int c = matrix[0].size();
        int i = 0, j = c - 1;
        while (i < r && j >= 0)
        {
            if (matrix[i][j] == k)
                return true;
            else if (matrix[i][j] > k)
                j--;
            else
                i++;
        }
        return false;
    }
};