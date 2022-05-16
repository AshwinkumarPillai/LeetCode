class Solution {
public:
    
    bool isValid(int i, int j, int n){
        return (i >=0 && j >= 0 && i < n && j < n);
    }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<pair<int, int>>q;
        q.push({0,0});
        int ans = 0;
        
        int n = grid.size();
        
        vector<pair<int, int>>dirs = {{-1,-1}, {-1,0}, {-1, 1}, {0,-1}, {0,1}, {1,-1}, {1, 0}, {1, 1}};
        
        while(!q.empty()){
            ans++;
            int sz = q.size();
            while(sz--){
                pair<int, int> p = q.front();q.pop();
                int i = p.first, j = p.second;
                if(grid[i][j] == 1) continue;
                if(i == n-1 && j == n-1) return ans;
                grid[i][j] = 1;
                for(pair<int, int>& dir: dirs){
                    int ni = i + dir.first , nj = j + dir.second;
                    if(isValid(ni, nj, n) && !grid[ni][nj]) q.push({ni, nj}); 
                }
                
            }
        }
        return -1;
    }
};