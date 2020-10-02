class Solution {
public:
    int minFlips(string target) {
        int ans = 0;
        int val = '0';
        for(char x: target){
            if(x != val){
                ans++;
            }
            val = x;
        }
        return ans;
    }
};
