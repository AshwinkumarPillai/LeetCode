class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length() != t.length()) return false;
        int n = s.length();
        map<char,char>m;
        map<char,char>m2;
        for(int i = 0;i<n;i++){
            char x = s[i];
            char y = t[i];
            if(m.find(x) == m.end()){
                if(m2.find(y) != m2.end()) return false;
                m[x] = y;
                m2[y] = x;
            }else if(m[x] != y) return false;
        }
        return true;
    }
};
