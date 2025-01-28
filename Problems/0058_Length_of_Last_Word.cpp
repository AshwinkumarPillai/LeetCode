// Single pass
class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.length(),ans = 0;
        if(!i) return 0;
        while(i > 0){
            i--;
            if(s[i] != ' ') ans++;
            else if(ans > 0) return ans;
        }  
        return ans;
    }
};

// Double pass
class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.length() - 1,ans = 0;
        while(i >= 0 && s[i] == ' ') i--;
        while(i>=0 && s[i] != ' '){
            i--;
            ans++;
        }
        return ans;
    }
};

// Using string back and pop
class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length(),ans = 0;
        if(!n) return 0;
        char t = s.back();
        while(t == ' '){
            s.pop_back();
            if(s.length()) t = s.back();
            else t = 'j';
        }
        while(s.length()){
            char x = s.back();
            if(x != ' ') ans++;
            else break;
            s.pop_back();
        }
        return ans;
    }
};

