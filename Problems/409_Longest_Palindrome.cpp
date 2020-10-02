class Solution {
public:
    int longestPalindrome(string s) {
        int odd = 0;
        map<char,int>m;
        for(char x: s){
            m[x]++;
        }
        
        int ans = 0;
        for(auto p:m){
            ans += p.second/2 ;
            if((p.second & 1)) odd++;
        }
        ans *= 2;
        return (odd) ? ans+1 : ans;
    }
};
