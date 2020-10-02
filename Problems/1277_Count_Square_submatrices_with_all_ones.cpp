class Solution {
public:
    int countSquares(vector<vector<int>>& m) {
        int r = m.size();
        int c = m[0].size();
        int count = 0;
        vector<vector<int>>dp(r,vector<int>(c));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(m[i][j] == 1){
                    int val = (i==0 || j== 0)? 1: min({dp[i-1][j], dp[i-1][j-1],dp[i][j-1]}) + 1;
                    count+=val;
                    dp[i][j] = val;
                }
            }
        }
        return count;
    }
};