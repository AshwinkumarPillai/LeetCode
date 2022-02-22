// DP
class Solution {
public:
    vector<int> arr = {0,1,1};
    int fib(int n) {
        if(n <= arr.size() - 1) return arr[n];
        for(int i=arr.size();i<=n+1;i++){
            arr.push_back(arr[i-1] + arr[i-2]);
        }
        return arr[n];
    }
};

// Iterative
class Solution {
public:
    
    int fib(int n) {
        if(n<=1) return n;
        return fib(n-1) + fib(n-2);
    }
};

