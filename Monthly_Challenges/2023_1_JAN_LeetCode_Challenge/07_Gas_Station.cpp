// Most Optimized O(n) Single pass elegant solution
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int total_tank = 0,curr_tank=0,start_station = 0;
        for(int i=0;i<n;i++){
            total_tank += gas[i] - cost[i];
            curr_tank += gas[i] - cost[i];
            if(curr_tank < 0){
                start_station = i + 1;
                curr_tank = 0;
            }
        }
        return (total_tank >=0) ? start_station : -1;
    }
};

// Single Pass only traverse unvisited green station
class Solution {
public:
    int station;
    int getNextValid(vector<int>& gas, vector<int>& cost,int i,int n){
        while(++i < n) if(gas[i] - cost[i] >= 0) return i;
        return -1;
    }
    
    bool startTrip(vector<int>& gas,vector<int>& cost,int start,int n){
        int end = start,avail = gas[start];
        while(true){
            avail -= cost[start];
            if(avail<0){
                if(station < start) station = start;
                else station = n;
                return false;
            }
            start = (start + 1) % n;
            if(start == end) return true;
            avail += gas[start];
        }
    }
    
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        station = getNextValid(gas,cost,-1,n);
        if(station == -1) return -1;
        while(station < n){
            if(startTrip(gas,cost,station,n)) return station;
            station = getNextValid(gas,cost,station,n);
            if(station == -1) return -1;
        }
        return -1;
    }
};

// Double pass - iterating for all green stations
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int g = 0,n = gas.size();
        vector<int>pos;
        for(int i=0;i<n;i++) {
            int x = gas[i] - cost[i];
            g += x;
            if(x >= 0) pos.push_back(i);
        }
        if(g < 0) return -1;
        int m = pos.size();
        for(int i=0;i<m;i++){
            int start = pos[i],end = pos[i];
            int avail = gas[start];
            while(true){
                avail -= cost[start];
                start = (start + 1) % n;
                if(avail < 0) break;
                if(start == end) return start;
                avail += gas[start];
            }
        }
        return -1;
    }
};
