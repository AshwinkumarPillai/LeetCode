class SubrectangleQueries {
public:
    vector<vector<int>>rect;
    SubrectangleQueries(vector<vector<int>>& rectangle) {
        rect = rectangle;
    }
    
    void updateSubrectangle(int r1, int c1, int r2, int c2, int v) {
        for(int i=r1;i<=r2;i++){
            for(int j=c1;j<=c2;j++){
                rect[i][j] = v;
            }
        }
    }
    
    int getValue(int row, int col) {
        return rect[row][col];
    }
};
