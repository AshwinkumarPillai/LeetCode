class Solution {
public:
    string reverseWords(string s) {
        if(s == "") return s;
        vector<string>v;
        int i=0,n=s.length();
        string ans = "";
        while(s[i] == ' ') i++;
        if(i == n) return "";
        string t = "";
        for(;i<n;i++){
            if(s[i] == ' '){
                if(t != ""){
                    v.push_back(t);
                    t="";   
                }
            }else{
                t += s[i];
            }
        }
        if(t != "") v.push_back(t);
        while(v.size()){
            ans+= v.back();
            ans+= ' ';
            v.pop_back();
        }
        ans.pop_back();
        return ans;
    }
};