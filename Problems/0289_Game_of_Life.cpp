// O(1) - Space
class Solution {
public:
    
    int getVal(vector<vector<int>>& b, int i, int j, int m, int n){
        if(i<0 || i >= m || j < 0 || j>= n) return 0;
        return (b[i][j] == 1 || b[i][j] == 2) ? 1 : 0;
    }
    
    int getLiveNeighbourCount(vector<vector<int>>& b, int i, int j, int m, int n){
        int sum = 0;
        vector<pair<int,int>> dirs = {{0,1}, {1,1}, {1,0}, {1,-1}, {0,-1}, {-1,-1}, {-1,0}, {-1, 1}};
        for(auto dir: dirs){
            sum += getVal(b, i + dir.first, j + dir.second, m, n);
        }
        return sum;
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int x = getLiveNeighbourCount(board, i, j, m, n);
                int val = board[i][j];
                if(val == 1 && (x < 2 || x > 3)) board[i][j] = 2;
                else if(val == 0 && x == 3) board[i][j] = 3;
            }
        }
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                board[i][j] %= 2;
            }
        }
    }
};

// O(n) - Space
class Solution {
public:
    
    int getVal(vector<vector<int>>& b, int i, int j, int m, int n){
        if(i<0 || i >= m || j < 0 || j>= n) return 0;
        return b[i][j];
    }
    
    int getLiveNeighbourCount(vector<vector<int>>& b, int i, int j, int m, int n){
        int sum = 0;
        vector<pair<int,int>>dirs = {{0,1}, {1,1}, {1,0}, {1,-1}, {0,-1}, {-1,-1}, {-1,0}, {-1, 1}};
        for(auto dir: dirs){
            sum += getVal(b, i + dir.first, j + dir.second, m, n);
        }
        return sum;
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        
        vector<vector<int>>ans(m, vector<int>(n));
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int x = getLiveNeighbourCount(board, i, j, m, n);
                int val = board[i][j];
                ans[i][j] = val;
                if(val == 1 && (x < 2 || x > 3)) ans[i][j] = 0;
                else if(val == 0 && x == 3) ans[i][j] = 1;
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                board[i][j] = ans[i][j];
            }
        }
    }
};
