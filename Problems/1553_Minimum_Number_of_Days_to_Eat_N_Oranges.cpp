// find the nearest reminder for n%2 and n%3 then eat that much 1 per day then eat all n/2 or 2n/3 whichever we reached first
// n%2 or n%3 is how much distance away n is from being divisible by 2 or 3 (which is done by just subtracting 1), which is best way to minimize the steps
// 1 is added because of operations(2nd or 3rd as specified in question) done to decrease n -> n/2 or n -> n/3
class Solution {
public:
    unordered_map<int,int>dp;
    int minDays(int n) {
        if (n <= 1) return n;
        if (dp.count(n) == 0) dp[n] = 1 + min(n % 2 + minDays(n / 2), n % 3 + minDays(n / 3));
        return dp[n];
    }
};
