//0 ms | Bit Manipulation
/*
    Explanation
    ----------------------------------
    We have 2 operations - divide by 2 when even and subtract 1 when odd
    and we need to get the number 0 at the end
    Here we can observe that the task becomes easy if we look at the binary representation
    for any number, for e.g. :
    10101101110
    we can do right shift which means dividing by 2 and if the number is odd i.e. the LSB is 1 we subtract 1 and then perform right shift
    so if LSB is 0 we increase count by 1 (num is even) and if LSB is 1 we increase count by 2 (subtracting and then dividing the resulting even number)
    10101101110  ans = 0
    1010110111  ans = 1
    101011011  ans = 3
    10101101  ans = 5
    1010110  ans = 7
    101011  ans = 8
    10101  ans = 10
    1010  ans = 12
    101  ans = 13
    10  ans = 15
    10  ans = 16
    1  ans = 17    -> do not increase count by 2 for the last 1. All numbers will have leading bit so in algo we can return ans - 1
    0  ans = 18

   In conclusion 

   Number of steps = number of division by 2 + number of substaction by 1 = length of num in binary rep (no. of right shifts) + number of set bits
*/
class Solution {
public:
    
    int numberOfSteps(int num) {
        if(!num) return 0;
        int ans = 0;
        while(num){
            ans += (num & 1) ? 2 : 1;
            num >>= 1;
        }
        return ans - 1;
    }
};

// not so useful DP solution
class Solution {
public:
    
    vector<int>dp;
    
    int numberOfSteps(int num) {
        if(num == 0) return 0;
        if(dp.size() == 0){
            dp.resize(1000000);
            dp[1] = 1;
            dp[2] = 2;
        }
        if(dp[num]) return dp[num];
        
        return dp[num] = 1 + numberOfSteps((num%2 == 0) ? num / 2 : num - 1);
    }
};