class Solution {
public:
    long long mp = 10000007;
     string rabinKarp(vector<int>& p,string s,int len){
        if(len==0)return "";
        int n=s.length();
        unordered_map<int,vector<int>> h;
        int curr=0;
        for(int i=0;i<len;i++){
            curr=(curr*26+(s[i]-'a'))%mp;  
        }
        h[curr]={0};
        for(int i=len;i<n;i++){
            curr=((curr-p[len-1]*(s[i-len]-'a'))%mp + mp)%mp;
            curr=(curr*26+(s[i]-'a'))%mp;
            if(h.find(curr) != h.end()){
                for(auto x  : h[curr]){
                    string sub= s.substr(i-len+1,len);
                    if(s.substr(x,len) == sub) return sub;
                }
                h[curr].push_back(i-len+1);
            }
            else h[curr]={i-len+1};
                
        }
        return "";
    }
    
    string longestDupSubstring(string s) {
        string ans = "";
        int low=0;
        int n=s.length();
        int high=n-1;
        
        vector<int> p;
        p.push_back(1);
        while(n--){
            p.push_back((p.back()*26)%mp);
        }
        while(low<=high){
            int mid = low + (high-low)/2;
            string  str = rabinKarp(p,s,mid);
            if(str.length()>ans.length()){
                ans = str;
                low = mid + 1;
            }
            else high = mid - 1;
        }
        return ans;
    }
};
