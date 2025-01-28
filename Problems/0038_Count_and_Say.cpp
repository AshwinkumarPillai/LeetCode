class Solution {
public:
    pair<int,int> countAndIndex(string& s,int index,int n){
        char x = s[index];
        int count = 1;
        while(index<n-1 && s[index] == s[index+1]){
            index++;
            count++;
        }
        return {count,index+1};
    }
    string countnums(string& s){
        int n = s.length();
        if(n == 1) return "11";
        int index = 0;
        string ans = "";
        while(index < n){
            char x = s[index];
            auto p = countAndIndex(s,index,n);
            index = p.second;
            ans = ans + to_string(p.first) + x;
        }
        return ans;
    }
    
    string countAndSay(int n) {
        string ans = "1";
        for(int i=1;i<n;i++){
            ans = countnums(ans);    
        }
        return ans;
    }
};
