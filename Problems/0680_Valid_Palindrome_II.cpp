class Solution {
public:
    
    bool isPalindrome(string& s, int i, int j){
        while(i<=j && s[i] == s[j]){i++;j--;}
        return i>j;
    }
    
    bool validPalindrome(string s) {
        int i = 0, j = s.length() - 1;
        while(i<=j && s[i] == s[j]){i++;j--;}
        if(i > j) return true;
        else if(j == i+1) return true;
        return isPalindrome(s, i, j-1) || isPalindrome(s, i+1, j);
    }
};
