class Solution {
public:
    int r,c,ans;
    bool check(int i,int j){
        return i>=0 && i<r && j>= 0 && j<c;
    }
    void backtrack(vector<vector<int>>& grid,int i,int j,int non_obstacles){
        if(grid[i][j] == 2 && non_obstacles == 1){
            ans++;
            return;
        }
        int temp = grid[i][j];
        grid[i][j] = -4;
        non_obstacles -= 1;
        vector<pair<int,int>>dirs = {{0,1},{0,-1},{1,0},{-1,0}};
        for(auto dir: dirs){
            int ii = i + dir.first, jj = j + dir.second;
            if(check(ii,jj) && grid[ii][jj] >=0) backtrack(grid,ii,jj,non_obstacles);
        }
        grid[i][j] = temp;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int non_obstacles = 0;
        pair<int,int>startCell = {0,0};
        r = grid.size();c=grid[0].size();
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                int val = grid[i][j];
                if(val >= 0) non_obstacles += 1;
                if(val == 1){
                    startCell.first = i;
                    startCell.second = j;
                }
            }
        }
        ans = 0;
        backtrack(grid,startCell.first,startCell.second,non_obstacles);
        return ans;
    }
};
