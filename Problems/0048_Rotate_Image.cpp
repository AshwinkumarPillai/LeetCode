class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i=0;i<(n+1)/2;i++){
            for(int j = 0;j<n/2;j++){
                int top = matrix[i][j];
                int left = matrix[n-1-j][i];
                int bottom = matrix[n-1-i][n-1-j];
                int right = matrix[j][n-1-i];
                
                matrix[i][j] = left;
                matrix[n-1-j][i] = bottom;
                matrix[n-1-i][n-1-j] = right;
                matrix[j][n-1-i] = top;
            }
        }
    }
};

class Solution {
public:
    
    void reverse(vector<vector<int>>& matrix){
        int n = matrix.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n/2;j++){
                swap(matrix[i][j], matrix[i][n-1-j]);
            }
        }
    }
    
    void transpose(vector<vector<int>>& matrix){
        int n = matrix.size();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
    
    void rotate(vector<vector<int>>& matrix) {
        transpose(matrix);
        reverse(matrix);
    }
};
