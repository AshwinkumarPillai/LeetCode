class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        int n = s.length(),m = t.length(),l=min(m,n);
        vector<int>shifts(26);
        for (int i = 0; i < l; i++) {
            int diff = (t[i] - s[i] + 26) % 26;
            if (diff > 0 && diff + shifts[diff] * 26 > k) {
                return false;
            }
            shifts[diff]++;
        }
        return (m==n);
    }
};
