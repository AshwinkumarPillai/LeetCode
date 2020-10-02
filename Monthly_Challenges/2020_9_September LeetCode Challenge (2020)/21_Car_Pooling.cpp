// Universal sol - one extra pass to check max number of stops
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int maxStop = 0;
        for(auto trip: trips) maxStop = max(maxStop,trip[2]);
        vector<int>stops(maxStop+1);
        vector<int>stops(1001);
        for(auto trip: trips){
            int x = trip[0];
            stops[trip[1]] += x;
            stops[trip[2]] -= x;
        }
        for(int x: stops){
            capacity -= x;
            if(capacity < 0) return false;
        }
        return true;
    }
};

// Max stop will not exceed - 1000
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int>stops(1001);
        for(auto trip: trips){
            int x = trip[0];
            stops[trip[1]] += x;
            stops[trip[2]] -= x;
        }
        for(int x: stops){
            capacity -= x;
            if(capacity < 0) return false;
        }
        return true;
    }
};
