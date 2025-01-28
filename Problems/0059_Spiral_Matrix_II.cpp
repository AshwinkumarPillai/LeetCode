// Optimized
class Solution {
public:
    
    int floorMod(int x, int y) {
        return ((x % y) + y) % y;
    }
    
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n));
        vector<pair<int, int>>dirs = {{0,1}, {1, 0}, {0, -1}, {-1, 0}};
        
        int num = 1, d = 0, N = n * n;
        int  i = 0, j = 0;
        while(num <= N){
            matrix[i][j] = num++;
            int r = floorMod(i + dirs[d].first, n);
            int c = floorMod(j + dirs[d].second, n);
            if(matrix[r][c] != 0) d = (d+1) % 4;
            i += dirs[d].first;
            j += dirs[d].second;
        }
        
        return matrix;
    }
};

// Simple
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n));
        
        int r1 = 0, r2 = n-1, c1 = 0, c2 = n-1;
        int num = 1;
        while(r1 <= r2 && c1 <= c2){
            for(int i = c1; i <= c2; i++) matrix[r1][i] = num++;
            r1++;
            for(int i = r1; i<= r2; i++) matrix[i][c2] = num++;
            c2--;
            for(int i = c2; i>= c1; i--) matrix[r2][i] = num++;
            r2--;
            for(int i = r2;i >= r1;i--) matrix[i][c1] = num++;
            c1++;
        }
        
        return matrix;
    }
};
