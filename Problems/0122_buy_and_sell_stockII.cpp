// Intuituve solution - calc the peak and valley which occurs one after the other and find diff to get profit
// for example - [1,2,3,4,5]:
// Here the first valley is 1 and when we find peak we will end up at 5. So there is only one valley and one peak and the ans is 5-1 = 4;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i = 0,valley=prices[0],peak = prices[0],ans=0,n = prices.size();
        while(i<n-1){
            while(i<n-1 && prices[i] >= prices[i+1]) i++;
            valley = prices[i];
            while(i<n-1 && prices[i] <= prices[i+1]) i++;
            peak = prices[i];
            ans += peak - valley;
        }
        return ans;
    }
};

// BRUTE FORCE
class Solution {
public:
    
    int calc(vector<int>& prices,int i){
        int n = prices.size();
        if(i >= n) return 0;
        int ans = 0;
        for(int start = i;start<n;start++){
            int maxprofit = 0;
            for(int j = start+1;i<n;i++){
                if(prices[start] < prices[j]){
                    int profit = calc(prices,j+1) + prices[i] - prices[start];
                    maxprofit = max(profit,maxprofit);
                }
            }
            ans = max(ans,maxprofit);
        }
        return ans;
    }
    
    int maxProfit(vector<int>& prices) {
        return calc(prices,0);
    }
};


// Old Solution, Implemented in monthly challenge
class Solution
{
public:
    int maxProfit(vector<int> &p)
    {
        int b = -1, s = 0;
        int profit = 0;
        int n = p.size();
        for (int i = 1; i < n; ++i)
        {
            if (b == -1)
            {
                if (p[i] > p[i - 1])
                {
                    b = i - 1;
                    s = i;
                }
            }
            else
            {
                if (p[i] > p[i - 1])
                    s = i;
                else if (p[i] < p[i - 1])
                {
                    profit += p[s] - p[b];
                    b = -1;
                }
            }
            if (i == (n - 1) && b != -1)
                profit += p[n - 1] - p[b];
        }
        return profit;
    }
};
