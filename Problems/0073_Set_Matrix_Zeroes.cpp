
// Method 1: Using set
// Time - O(MN) | Space - O(M+N)

void setZeroes(vector<vector<int>>& matrix) {
    set<int>row;
    set<int>col;
    int m = matrix.size();
    if(!m) return;
    int n = matrix[0].size();
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(matrix[i][j] == 0) {
                row.insert(i);
                col.insert(j);
            }
        }
    }
    
    for(int i: row){
        for(int j= 0; j<n; j++) matrix[i][j] = 0;
    }
    
    for(int j: col){
        for(int i = 0;i<m;i++) matrix[i][j] = 0;
    }
}


// Method 2: Using array (more effecient than using set)
// Time - O(MN) | Space - O(M+N)

void setZeroes(vector<vector<int>>& matrix) {
    int m = matrix.size();
    if(!m) return;
    int n = matrix[0].size();
    vector<bool>row(m);
    vector<bool>col(n);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(matrix[i][j] == 0) {
                row[i] = true;
                col[j] = true;
            }
        }
    }
    
    for(int i=0;i<m;i++){
        if(row[i]){
            for(int j= 0; j<n; j++) matrix[i][j] = 0;    
        }
    }
    
    for(int j=0;j<n;j++){
        if(col[j]){
            for(int i = 0;i<m;i++) matrix[i][j] = 0;    
        }
    }      
}


// Method 3: Inplace
// Time -  O(MN) | Space - O(1)

void setZeroes(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    bool rowHasZero = false, colHasZero = false;
    for(int i=0;i<m;i++) if(matrix[i][0] == 0) colHasZero = true; // check if first col has zero
    for(int j=0;j<n;j++) if(matrix[0][j] == 0) rowHasZero = true; // check if first row has zero
    // Iterate rest of the matrix
    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            // if value is 0 then set corresponding row and column as 0
            if(matrix[i][j] == 0){
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }
    
    // Iterate again and use first row and col as the checks to see if the cell needs to be 0
    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            if(matrix[i][0] == 0 || matrix[0][j] == 0){
                matrix[i][j] = 0;
            }
        }
    }
    // if first row or first col had any zero then set the row or col to 0
    if(rowHasZero) for(int j=0;j<n;j++) matrix[0][j] = 0;
    if(colHasZero) for(int i=0;i<m;i++) matrix[i][0] = 0;
}
