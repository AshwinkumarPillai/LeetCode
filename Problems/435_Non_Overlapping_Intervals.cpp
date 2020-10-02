// Greedy - sort by end
class Solution {
public:
    static bool compare(vector<int>&a,vector<int>&b){
        return a[1] < b[1];
    }
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(!n) return 0; 
        sort(intervals.begin(),intervals.end(),compare);
        int prev = intervals[0][1],count = 1;
        for(int i=1;i<n;i++){
            if(intervals[i][0] >= prev){
                prev = intervals[i][1];
                count++;
            }
        }
        return n - count;
    }
};

// Greedy - sort by start
class Solution {
public:
    static bool compare(vector<int>&a,vector<int>&b){
        return a[0] < b[0];
    }
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(!n) return 0; 
        sort(intervals.begin(),intervals.end(),compare);
        int end = intervals[0][1],prev=0,ans = 0;
        for(int i=1;i<n;i++){
            if(intervals[prev][1] > intervals[i][0]){
                if(intervals[prev][1] > intervals[i][1]){
                    prev = i;
                }
                ans++;
            }else{
                prev = i;
            }
        }
        return ans;
    }
};

// DP - sort by end
class Solution {
public:
    static bool compare(vector<int>&a,vector<int>&b){
        return a[1] < b[1];
    }
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(!n) return 0; 
        sort(intervals.begin(),intervals.end(),compare);
        vector<int>dp(n);
        dp[0] = 1;
        int include = 1;
        for(int i=1;i<n;i++){
            int maxval = 0;
            for(int j= i-1;j>=0;j--){
                if(intervals[j][1] <= intervals[i][0]){
                    maxval = max(maxval,dp[j]);
                    break;
                }
            }
            dp[i] = max(maxval + 1,dp[i-1]);
            include = max(include,dp[i]);
        }
        return n - include;
    }
};

// DP - sort by start
class Solution {
public:
    static bool compare(vector<int>&a,vector<int>&b){
        return a[0] < b[0];
    }
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(!n) return 0; 
        sort(intervals.begin(),intervals.end(),compare);
        vector<int>dp(n);
        dp[0] = 1;
        int include = 1;
        for(int i=1;i<n;i++){
            int maxval = 0;
            for(int j= i-1;j>=0;j--){
                if(intervals[j][1] <= intervals[i][0])
                    maxval = max(maxval,dp[j]);
            }
            dp[i] = maxval + 1;
            include = max(include,dp[i]);
        }
        return n - include;
    }
};

// Brute Force
class Solution {
public:
    static bool compare(vector<int>&a,vector<int>&b){
        return a[1] < b[1];
    }
    
    int helper(int prev,int curr,vector<int>&intervals){
        if(intervals.size() == curr) return 0;
        int include = INT_MAX,exclude;
        if(prev == -1 || intervals[prev][1] <= intervals[curr][1])
            include = helper(curr,curr+1,intervals);
        exclude = helper(prev,curr+1,intervals) + 1;
        return min(include,exclude);
    }
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(!n) return 0; 
        sort(intervals.begin(),intervals.end(),compare);
        return helper(-1,0,intervalse);
    }
};
