// Sorting
class Solution {
public:
    char findTheDifference(string s, string t) {
        sort(s.begin(),s.end());sort(t.begin(),t.end());
        int n = s.length();
        for(int i=0;i<n;i++){
            if(s[i] != t[i]) return t[i];
        }
        return t[n];
    }
};

// Using XOR
class Solution {
public:
    char findTheDifference(string s, string t) {
        int xr = 0;
        for(char x: s) xr ^= x;
        for(char x: t) xr ^= x;
        return char(xr);
    }
};

// Using Map - odd entries
class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int>m;
        for(char x: s) m[x]++;
        for(char x: t) m[x]++;
        for(auto p: m) if((p.second & 1)) return p.first;
        return 'a';
    }
};


// Using Map - first bad entry
class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int>m;
        for(char x: s) m[x]++;
        for(char x: t){
            if(m[x] < 1) return x;
            else m[x]--;
        }
        return 'a';
    }
};
