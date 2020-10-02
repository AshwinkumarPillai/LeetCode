class Solution {
public:
    int numSplits(string s) {
        int n = s.length();
        if(n == 1) return 1;
        vector<int>prefix(n),suffix(n);
        set<char>st;
        for(int i=0;i<n;i++){
            st.insert(s[i]);
            prefix[i] = st.size();
        }
        st.clear();
        for(int i=n-1;i>=0;i--){
            st.insert(s[i]);
            suffix[i] = st.size();
        }
        int ans = 0;
        for(int i=0;i<n-1;i++){
            ans += (prefix[i] == suffix[i+1]);
        }
        return ans;
    }
};
