
// Memoization
class Solution {
public:
    
    int dp[601][101][101] = {};
    
    int sz = 0;
    
    vector<int> zeroCnt;
    vector<int>oneCnt;
    
    int checkString(vector<string>& strs, int i, int m, int n){
        if(i == sz || (m == 0 && n == 0)) return 0;
        if(dp[i][m][n] != -1) return dp[i][m][n];
        if((zeroCnt[i] > m) || (oneCnt[i] > n)) return dp[i][m][n] = checkString(strs, i+1, m, n);
        
        int a = 1 + checkString(strs, i+1, m - zeroCnt[i], n - oneCnt[i]);
        int b = checkString(strs, i+1, m, n);
        return dp[i][m][n] = max(a, b);
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        sz = strs.size();
        zeroCnt.resize(sz);
        oneCnt.resize(sz);
        
        memset(dp , -1 , sizeof(dp));
        
        for(int i = 0 ;i < sz; i++){
            for(char x: strs[i]){
                if(x == '0') zeroCnt[i]++;
                else oneCnt[i]++;
            }
        }
        
        return checkString(strs, 0, m, n);
    }
};

// Backtracking
class Solution {
public:
    
    int sz = 0;
    
    vector<int> zeroCnt;
    vector<int>oneCnt;
    
    int checkString(vector<string>& strs, int i, int m, int n){
        if(i == sz || m == 0 || n == 0) return 0;
        if((zeroCnt[i] > m) || (oneCnt[i] > n)) return checkString(strs, i+1, m, n);
        
        int a = 1 + checkString(strs, i+1, m - zeroCnt[i], n - oneCnt[i]);
        int b = checkString(strs, i+1, m, n);
        return max(a, b);
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        sz = strs.size();
        zeroCnt.resize(sz);
        oneCnt.resize(sz);
        
        for(int i = 0 ;i<n; i++){
            for(char x: strs[i]){
                if(x == '0') zeroCnt[i]++;
                else oneCnt[i]++;
            }
        }
        
        return checkString(strs, 0, m, n);
    }
};