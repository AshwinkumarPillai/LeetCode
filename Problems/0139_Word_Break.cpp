// Recursion + memo - O(n2)
class Solution {
public:
    bool helper(string& s,set<string>& st,int i,int n,vector<int>& dp){
        if(i == n) return true;
        if(dp[i] != -1) return dp[i];
        for(int j = i+1;j<=n;j++){
            if(st.find(s.substr(i,j-i)) != st.end() && helper(s,st,j,n,dp)){
                dp[i] = 1;
                return true;
            }
        }
        dp[i] = 0;
        return false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        set<string>st(wordDict.begin(),wordDict.end());
        vector<int>dp(n,-1);
        return helper(s,st,0,n,dp);
    }
};

// BFS - O(n2)
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        set<string>st(wordDict.begin(),wordDict.end());
        vector<int>visited(n);
        queue<int>q;
        q.push(0);
        while(!q.empty()){
            int i = q.front();q.pop();
            if(!visited[i]){
                for(int j = i+1;j<=n;j++){
                    if(st.find(s.substr(i,j-i)) != st.end()){
                        q.push(j);
                        if(j == n) return true;
                    }
                }
                visited[i] = 1;
            }
        }
        return false;
    }
};
