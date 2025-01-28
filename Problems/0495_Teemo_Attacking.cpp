class Solution {
public:
    int findPoisonedDuration(vector<int>& ts, int d) {
        int ans = 0,range = 0;
        for(int x: ts){
            if(x >= range) 
                ans += d;
            else
                ans += (d - range + x);
            range = x + d;
        }
        return ans;
    }
};
