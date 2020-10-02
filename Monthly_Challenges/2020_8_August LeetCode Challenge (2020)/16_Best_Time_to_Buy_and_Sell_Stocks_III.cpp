class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n <= 1) return 0;
        int minval = prices[0];
        vector<int>left(n);
        for(int i=1;i<n;i++){
            if(prices[i] - minval > left[i-1]){
                left[i] = prices[i] - minval;
            }else left[i] = left[i-1];
            minval = min(minval,prices[i]);
        }
        int maxval = prices[n-1];
        vector<int>right(n);
        for(int i=n-2;i>=0;i--){
            if(maxval - prices[i] > right[i+1]) right[i] = maxval - prices[i];
            else right[i] = right[i+1];
            maxval = max(maxval,prices[i]);
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            ans = max(ans,left[i]+right[i]);
        }
        return ans;
    }
};
