// Two other approaches are - Rabin Karp and KMP  - Classic pattern matching algos

// regex
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        regex pattern("^(.+)\\1+$");
        return regex_match(s,pattern);
    }
};

// Brute force
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length();
        for(int i=1;i<=n/2;i++){
            string sub = s.substr(0,i);
            string t = "";
            while(t.length() < s.length()) t+= sub;
            if(t == s) return true;
        }
        return false;
    }
};

// Elegant code
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        return (s + s).substr(1, 2 * s.size() - 2).find(s) != string::npos;
    }
};
