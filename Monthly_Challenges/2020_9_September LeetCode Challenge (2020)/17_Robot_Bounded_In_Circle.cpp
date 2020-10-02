class Solution {
public:
    bool isRobotBounded(string instructions) {
        vector<pair<int,int>>dirs = {{0,1},{1,0},{0,-1},{-1,0}};
        int x = 0,y=0,index = 0;
        for(char i: instructions){
            if(i=='L') index = (index+3) % 4;
            else if(i=='R') index = (index + 1) % 4;
            else{
                x += dirs[index].first;
                y += dirs[index].second;
            }
        }
        return (x == 0 && y == 0) || (index != 0);
    }
};
