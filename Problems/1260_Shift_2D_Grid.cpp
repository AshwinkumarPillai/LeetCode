class Solution {
public:
    
    pair<int,int> getCoordinate(int x, int n){
        if(x % n == 0) return {(x / n) - 1, n-1};
        return {x / n, (x % n) - 1};
    }
    
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int N = m*n;
        vector<vector<int>>ans(m, vector<int>(n));
        for(int x  = 1; x<= N; x++){
            int y = (x + k) % N == 0 ? N : (x + k) % N;
            auto p = getCoordinate(x, n);
            auto q = getCoordinate(y, n);
            ans[q.first][q.second] = grid[p.first][p.second] ;
        }
        return ans;
    }
};
