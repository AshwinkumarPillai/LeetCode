class Solution {
public:
    bool isCapital(char x){
        return (int(x) >= int('A') && int(x) <= int('Z'));
    }
    
    bool detectCapitalUse(string word) {
        int cap = 1,small = 1,cs = 1,n = word.length();
        if(n == 1) return true;
        if(!isCapital(word[0])) {cap=0;cs = 0;}
        
        for(int i=1;i<n;i++){
            if(!isCapital(word[i])) cap = 0;
            else{
                small = 0;
                cs = 0;
            }
        }
        return (cap || small || cs);
    }
};