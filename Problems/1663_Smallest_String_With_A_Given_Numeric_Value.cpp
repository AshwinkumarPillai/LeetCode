class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans = "";
        for(int i=0;i<n;i++) ans += 'a';
        k = k - n;
        int i = n-1;
        while(i>=0 && k>0){
            if(k < 25) {
                ans[i] = (char) 'a' + k;
                k = 0;
            }
            else{
                ans[i] = (char) 'a' + 25;
                k -= 25;
            }
            i--;
        }
        return ans;
    }
};
