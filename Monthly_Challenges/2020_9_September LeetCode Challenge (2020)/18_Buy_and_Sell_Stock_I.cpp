class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minval = INT_MAX,ans = 0;
        for(int x: prices){
            if(x < minval) minval = x;
            else{
                ans = max(x-minval,ans);
            }
        }
        return ans;
    }
};
