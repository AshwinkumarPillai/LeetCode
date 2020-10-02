class Solution {
public:
    int n;
    long dp(vector<int>& arr,int curr,int dest,int fuel,vector<vector<long>>& memo){
        if(fuel<0) return 0;
        if(memo[curr][fuel] != -1) return memo[curr][fuel];
        long ans = (curr == dest) ? 1 : 0;
        for(int i=0;i<n;i++)
            if(i != curr)
                ans = (ans + dp(arr,i,dest,fuel-abs(arr[curr] - arr[i]),memo)) % long(1e9+7);
        return memo[curr][fuel] = ans;
    }
    
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        n = locations.size();
        vector<vector<long>> memo(n,vector<long>(fuel+1,-1));
        return dp(locations,start,finish,fuel,memo);
    }
};
