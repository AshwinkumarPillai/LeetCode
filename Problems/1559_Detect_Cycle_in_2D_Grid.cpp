class Solution {
public:
    int loop = false;
    vector<vector<char>>g;
    vector<vector<int>>visited;
    int r = 0,c = 0;
    
    
    bool check(int i,int j,int r,int c){
        return i>=0 && j>=0 && i<r && j<c;
    }
    void dfs(int i,int j){
        char x = g[i][j];
        vector<pair<int,int>>dirs = {{0,1},{1,0},{-1,0},{0,-1}};
        for(auto dir: dirs){
            int ii = i+dir.first, jj = j + dir.second;
            if(check(ii,jj,r,c) && g[ii][jj] == x){
                if(visited[ii][jj]){
                    if(visited[ii][jj] < visited[i][j] - 1) loop = true;
                }else{
                    visited[ii][jj] = visited[i][j]+1;
                    dfs(ii,jj);
                }
            }
        }
    }
    
    bool containsCycle(vector<vector<char>>& grid) {
        g = grid;
        r = grid.size();
        c = grid[0].size();
        visited.resize(r,vector<int>(c,0));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(!visited[i][j]){
                    visited[i][j] = 1;
                    dfs(i,j);
                }
            }
        }
        return loop;
    }
};
