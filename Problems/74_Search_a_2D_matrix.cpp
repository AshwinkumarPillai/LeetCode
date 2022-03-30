class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int i = 0, j = n - 1;
        
        while(i<m && j >= 0){
            int x = matrix[i][j];
            if(x == target) return true;
            if(target > x) i++;
            else if(target < x) j--;
            else return false;
        }
        return false;
    }
};