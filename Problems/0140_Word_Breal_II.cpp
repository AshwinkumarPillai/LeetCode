class Solution {
public:
    vector<string> splitFill(string &s,set<string>& dict,int index,int n,map<int,vector<string>>& dp){
        if(dp.find(index) != dp.end()) return dp[index];
        vector<string>ans;
        for(int i = index;i<n;i++){
            string t = s.substr(index,i-index+1);
            if(dict.count(t)){
                if(i == n-1) ans.push_back(t);
                vector<string> tmp = splitFill(s, dict, i + 1,n, dp);
                for(string x :tmp) ans.push_back(t + " " + x);
            }
        }
        return dp[index] = ans;
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        set<string>dict;
        for(string x: wordDict) dict.insert(x);
        map<int,vector<string>>dp;
        return splitFill(s,dict,0,n,dp);
    }
};
