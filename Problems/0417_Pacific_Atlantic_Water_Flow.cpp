class Solution {
public:
    
    vector<pair<int,int>>dirs = {{0,1},{1,0},{-1,0},{0,-1}};
    int r,c;
    
    bool isValid(int i, int j){
        return (i>=0 && i<r && j>=0 && j<c);
    }
    
    vector<vector<bool>> bfs(queue<vector<int>>& q,vector<vector<int>>& matrix){
        vector<vector<bool>>ans(r,vector<bool>(c,false));
        while(!q.empty()){
            vector<int> node = q.front();q.pop();
            int i = node[0],j = node[1];
            ans[i][j] = true;
            for(auto dir: dirs){
                int ii = i + dir.first,jj = j + dir.second;
                if(isValid(ii,jj) && (!ans[ii][jj]) && (matrix[ii][jj] >= matrix[i][j])){
                    q.push({ii,jj});
                }
            }
        }
        return ans;
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        r = matrix.size();
        if(!r) return {};
        c = matrix[0].size();
        if(!c) return {};
        queue<vector<int>>pacq;
        queue<vector<int>>atlq;
        for(int i=0;i<r;i++){
            pacq.push({i,0});
            atlq.push({i,c -1});
        }
        for(int i=0;i<c;i++){
            pacq.push({0,i});
            atlq.push({r-1,i});
        }
        
        vector<vector<bool>>pacific = bfs(pacq,matrix);
        vector<vector<bool>>atlantic = bfs(atlq,matrix);
        vector<vector<int>>ans;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(pacific[i][j] && atlantic[i][j]) ans.push_back({i,j});
            }
        }
        return ans;
    }
};
