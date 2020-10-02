class Solution {
public:
    unordered_map<int, int> p;
    
    int find(int x) {
        if (!p.count(x)) return p[x] = x;
        if (p[x] == x) return x;
        return p[x] = find(p[x]);
    }
    
    int largestComponentSize(vector<int>& A) {
        int n = A.size();
        for (int x : A)
            p[x] = x;
        for (int x : A) 
            for (int i = 2; i <= sqrt(x); ++i)
                if (x % i == 0) {
                    p[find(x)] = p[find(i)];
                    p[find(x)] = p[find(x / i)];
                }
        unordered_map<int, int> count;
        int ans = 1;
        for (int x : A)
            ans = max(ans, ++count[find(x)]);
        return ans;
    }
};
