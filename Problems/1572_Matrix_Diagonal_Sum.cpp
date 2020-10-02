// O(n) - number of rows; O(sqrt(n)) - number of elements
class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int ans = 0,n=mat.size();
        for(int i=0;i<n;i++){
            ans+= (mat[i][i] + mat[i][n-i-1]);
        }
        if((n&1)) ans -= mat[n/2][n/2];
        return ans;
    }
};

// O(n2) - n = number of rows;  O(n) - n = number of elements
class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int ans = 0,n=mat.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i == j) ans+= mat[i][j];
                else if(i+j == n-1) ans+=mat[i][j];
            }
        }
        return ans;
    }
};
