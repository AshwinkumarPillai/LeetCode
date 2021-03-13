class Solution {
public:
    int prime = 1e9+7;
    
    void computeDp(vector<int>&arr, vector<long>& dp,int i, map<int,int>& m){
        int x = arr[i];
        for(int j=0;j<i;j++){
            int y = arr[j];
            int div = x / y, mod = x % y;
            if((mod == 0)  && m.find(div) != m.end()){
                dp[i] += ((dp[m[y]]*dp[m[div]]) % prime);
            }
        }
    }
    
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n = arr.size();
        vector<long>dp(n,1);
        map<int,int>m;
        for(int i=0;i<n;i++) m[arr[i]]=i;
        for(int i=0;i<n;i++) computeDp(arr,dp,i,m);
        long ans = 0;
        for(long x: dp) ans += x;
        return ans % prime;
    }
};
