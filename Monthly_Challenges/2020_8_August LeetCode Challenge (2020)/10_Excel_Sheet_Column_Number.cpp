// Left to right
class Solution {
public:
    int titleToNumber(string s) {
        int n = s.length();
        long long ans = 0;
        for(int i=0;i<n;i++){
            long long x = (s[i] - 'A') + 1;
            ans = ans* 26 + x;
        }
        return ans;
    }
};

// Right to left
class Solution {
public:
    int titleToNumber(string s) {
        int n = s.length(),index;
        long long ans = 0,val =26;
        ans = (s[n-1] - 'A') + 1;
        index = n-2;
        while(index>=0){
            long long x = (s[index] - 'A') + 1;
            ans += (val * x);
            index--;
            val*=26;
        }
        return ans;
    }
};
