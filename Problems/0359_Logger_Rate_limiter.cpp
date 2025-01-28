// MAP
class Logger {
public:
    
    map<string,int>m;
    
    bool shouldPrintMessage(int timestamp, string message) {
        if(m.find(message) == m.end()){
            m[message] = timestamp;
            return true;
        }
        int t = m[message];
        if(timestamp - t < 10) return false;
        m[message] = timestamp;
        return true;
    }
};

// queue and set
class Logger {
public:
    queue<pair<string,int>>q;
    set<string>s;
    
    bool shouldPrintMessage(int timestamp, string message) {
        while(!q.empty()){
            auto p = q.front();
            if(timestamp - p.second >= 10){
                q.pop();
                s.erase(p.first);
            }
            else break;
        }
        if(s.count(message)) return false;
        q.push({message,timestamp});
        s.insert(message);
        return true;
    }
};
