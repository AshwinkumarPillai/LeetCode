
// Dp for all 365 days
class Solution {
public:
    vector<int>costs;
    vector<int>travel_days;
    vector<int>memo;
    
    int dp(int day){
        if(day>365) return 0;
        if(memo[day]) return memo[day];
        int ans;
        if(travel_days[day])
            ans = min({dp(day+1) + costs[0],dp(day+7) + costs[1],dp(day+30) + costs[2]});
        else ans = dp(day+1);
        return memo[day] = ans;
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        travel_days.resize(366);memo.resize(366);
        for(int x: days) travel_days[x]=1;
        this->costs = costs;
        return dp(1);
    }
};

// Dp for only the window of Days
class Solution {
public:
    vector<int>costs;
    vector<int>days;
    int n;
    vector<int>memo;
    vector<int> durations = {1,7,30};
    
    int dp(int i){
        if(i>=n) return 0;
        if(memo[i]) return memo[i];
        int ans = INT_MAX,j=i;
        for(int k=0;k<3;k++){
            while(j<n && days[j] < days[i] + durations[k]) j++;
            ans = min(ans,dp(j)+costs[k]);
        }
        return memo[i] = ans;
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        this->days = days;
        n = days.size();
        memo.resize(n);
        this->costs = costs;
        return dp(0);
    }
};
