class Solution {
public:
    
    int checkBounds(int i,int j,int r, int c){
        return i>=0 && i<r && j>=0 && j< c;
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        queue<pair<int,int>>q;
        int fresh = 0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                int x = grid[i][j];
                if(x == 1) fresh++;
                else if(x == 2) q.push({i,j});
            }
        }
        int time = 0;
        vector<pair<int,int>> dirs = {{-1,0},{0,1},{1,0},{0,-1}};
        while(!q.empty() && fresh > 0){
            int sz = q.size();
            while(sz--){
                auto p = q.front();
                q.pop();
                for(auto dir: dirs){
                    int i = p.first + dir.first, j = p.second + dir.second;
                    if(checkBounds(i,j,r,c) && grid[i][j] == 1){
                        grid[i][j] = 2;
                        fresh--;
                        q.push({i,j});
                    }
                }
            }
            time++;
        }
        return (fresh == 0) ? time : -1;
    }
};
