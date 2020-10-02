// Solution 1
class Solution {
public:
    string thousandSeparator(int num) {
        string s = to_string(num), ans;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            if (i > 0 && (n - i) % 3 == 0) ans += ".";
            ans += s[i];
        }
        return ans;
    }
};

// Solution 2
class Solution {
public:
    string thousandSeparator(int n) {
        string ans = "";
        if(n == 0) return "0";
        int t = 0;
        while(n){
            if(t == 3){
                ans += ".";
                t = 0;
            }
            
            int val = n%10;
            n/=10;
            ans += to_string(val);
            t++;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
