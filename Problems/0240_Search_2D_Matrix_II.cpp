class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = matrix.size(),c;
        if(r) c = matrix[0].size();
        int i = r-1,j=0;
        while(i>=0 && j < c){
            int x = matrix[i][j];
            if(x == target) return true;
            (target > x) ? j++ : i--; 
        }
        return false;
    }
};
