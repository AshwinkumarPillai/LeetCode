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

// Memoization - using map
class Solution {
public:
    
    int fib(int n, unordered_map<int, int>& m){
        if(m.find(n) != m.end()) return m[n];
        return m[n] = fib(n-1,m) + fib(n-2,m);
    }
    
    int fib(int n) {
        unordered_map<int, int>m;
        m[0] = 0;m[1] = 1;m[2] = 1;
        return fib(n, m);
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