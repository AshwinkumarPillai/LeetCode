class Solution {
public:
    int val(char c){
        if(c=='I') return 1;
        else if(c=='V') return 5;
        else if(c=='X') return 10;
        else if(c=='L') return 50;
        else if(c=='C') return 100;
        else if(c=='D') return 500;
        else if(c=='M') return 1000;
      return 0;
    }
    
    int romanToInt(string s) {
        int ans = 0,n = s.length();
        for(int i=0;i<n;i++){
            int si = val(s[i]),si1=val(s[i+1]);
            if(i<n-1){
                if(si < si1){
                    ans += (si1 - si);
                    i++;
                }else ans += si;
            }else ans += si;
        }
        return ans;
    }
};
