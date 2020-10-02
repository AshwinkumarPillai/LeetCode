class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& cd) {
        if(cd.size() == 2){
            return true;
        }
        int x1 = cd[0][0];
        int x2 = cd[1][0];
        int y1 = cd[0][1];
        int y2 = cd[1][1];
        
        if(x2 - x1 == 0){
            return false;
        }
        
        float m = (y2 - y1) / (x2 - x1);
        
        float c = y2 - (m*x2);
        
        for(int i = 2;i<cd.size();i++){
            int y = (m*cd[i][0]) + c;
            if(y!= cd[i][1]){
                return false;
            }
        }
        return true;
    }
};