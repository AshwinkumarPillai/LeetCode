class UndergroundSystem {
public:
    map<int,pair<string,int>>person;
    map<pair<string,string>,int>avgm;
    vector<pair<int,int>>avg;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        person[id] = {stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto p = person[id];
        if(avgm.find({p.first,stationName}) == avgm.end()){
            int n = avg.size();
            avg.push_back({t-p.second,1});
            avgm[{p.first,stationName}] = n;
        }else{
            int index = avgm[{p.first,stationName}];
            avg[index].second++;
            avg[index].first += (t-p.second);
        }
    }
    
    double getAverageTime(string startStation, string endStation) {
        int index = avgm[{startStation, endStation}];
        auto p = avg[index];
        return double(p.first)/double(p.second);
    }
};
