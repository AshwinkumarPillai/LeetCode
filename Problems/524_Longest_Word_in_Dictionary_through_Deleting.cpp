class Solution {
public:
    
    bool exists(string &s, string &t){
        int i = 0,j=0,m = s.length(),n=t.length();
        while(i<m){
            if(s[i] == t[j]) j++;
            i++;
            if(j == n) return true;
        }
        return false;
    }
    
    string findLongestWord(string s, vector<string>& d) {
        int maxL = 0;
        string ans = "";
        sort(d.begin(),d.end());
        for(string x: d){
            int l = x.length();
            if(l > maxL){
                if(exists(s,x)){
                    ans = x;
                    maxL = l;
                }
            }
        }
        return ans;
    }
};
