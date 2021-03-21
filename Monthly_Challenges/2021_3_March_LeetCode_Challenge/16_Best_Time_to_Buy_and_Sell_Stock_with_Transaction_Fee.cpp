class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int cash = 0,stocks = -prices[0];
        for(int x: prices){
            cash = max(cash,x + stocks - fee);
            stocks = max(stocks,cash - x);
        }
        return cash;
    }
};
