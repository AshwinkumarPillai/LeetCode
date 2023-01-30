// Iterative approach
class Solution
{
public:
    int tribonacci(int n)
    {
        if (n == 0 || n == 1)
            return n;
        if (n == 2)
            return 1;
        long t0 = 0, t1 = 1, t2 = 1;
        long ans = 0;
        for (int i = 3; i <= n; i++)
        {
            ans = (t0 + t1 + t2);
            t0 = t1;
            t1 = t2;
            t2 = ans;
        }
        return ans;
    }
};

// Recursion with memoization
class Solution
{
public:
    vector<int> memo;

    int recFib(int n)
    {
        if (memo[n] != -1)
            return memo[n];
        return memo[n] = recFib(n - 1) + recFib(n - 2) + recFib(n - 3);
    }

    int tribonacci(int n)
    {
        memo.resize(38, -1);
        memo[0] = 0;
        memo[1] = 1;
        memo[2] = 1;
        recFib(n);
        return memo[n];
    }
};