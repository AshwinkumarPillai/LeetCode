class Solution {
public:
    int r,c;
    vector<pair<int,int>>dirs = {{0,1},{0,-1},{1,0},{-1,0}};
    
    bool check(int i,int j){
        return i>=0 && j>=0 && i<r && j<c;
    }
    
    void dfs(vector<vector<int>>& grid,int i,int j,vector<vector<int>>& visited){
        visited[i][j] = 1;
        for(auto dir: dirs){
            int ii = dir.first + i,jj = dir.second+j;
            if(check(ii,jj) && grid[ii][jj] && !visited[ii][jj]) dfs(grid,ii,jj,visited);
        }
    }
    
    bool isDisConnected(vector<vector<int>>& grid){
        vector<vector<int>> visited(r,vector<int>(c));
        int count = 0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j] == 1 && !visited[i][j]){
                    dfs(grid,i,j,visited);
                    if((++count) > 1) return true;
                }
            }
        }
        return false;
    }
    
    int minDays(vector<vector<int>>& grid) {
        r = grid.size();
        c = grid[0].size();
        if(isDisConnected(grid)) return 0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j] == 1){
                    grid[i][j] = 0;
                    if(isDisConnected(grid)) return true;
                    grid[i][j] = 1;
                }
            }
        }
        return 2;
    }
};
