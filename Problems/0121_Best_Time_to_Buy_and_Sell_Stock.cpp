// O(n) solution
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprice = INT_MAX;
        int ans = 0,n= prices.size();
        for(int i=0;i<n;i++){
            if(prices[i] < minprice) minprice = prices[i];
            else if(prices[i] - minprice > ans) ans = prices[i] - minprice;
        }
        return ans;
    }
};

// Brute Force Solution
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int ans = 0,n=prices.size();
//         for(int i=0;i<n-1;i++){
//             for(int j=i+1;j<n;j++){
//                 int profit = prices[j] - prices[i];
//                 ans = max(profit,ans);
//             }
//         }
//         return ans;
//     }
// };
