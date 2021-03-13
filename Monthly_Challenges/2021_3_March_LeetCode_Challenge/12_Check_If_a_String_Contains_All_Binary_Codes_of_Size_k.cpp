// Custom Hash function - Rolling Hash
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = 1<<k,l=s.length();
        vector<bool> ans(n);
        int allOne = n-1;
        int hash = 0;
        for(int i=0;i<l;i++){
            hash = ((hash<<1) & allOne) | (s[i] - '0');
            if(i>=k-1 && !ans[hash]){
                ans[hash] = true;
                if(--n == 0) return true;
            }
        }
        return false;
    }
};

// Using Set
class Solution {
public:
    bool checkSubStrings(string &s, int n, int k){
        int l = s.length();
        set<string>st;
        for(int i=0;i<l-k+1;i++){
            st.insert(s.substr(i,k));
            if(st.size() == n) return true;
        }
        return false;
    }
    
    bool hasAllCodes(string s, int k) {
        int n = 1<<k;
        return checkSubStrings(s,n,k);
    }
};
