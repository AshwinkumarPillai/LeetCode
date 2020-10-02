class Solution {
public:
    void fillList(list<vector<int>>& l,int level,int val){
        int lev = level;
        auto it = l.begin();
        for(;it!= l.end();it++){
            auto x = *it;
            if(x[0] >= val){
                if(--level == 0){
                    break;
                }
            }
        }
        it++;
        if(it == l.end()){
            l.push_back({val,lev});
        }else{
            while(it!=l.end()){
                auto x = *it;
                if(x[0] >= val){
                    break;
                }
                it++;
            }
            l.insert(it,{val,lev});
        }
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& p) {
        vector<vector<int>>ans;
        list<vector<int>>l;
        map<int,set<int>>m;
        for(auto x: p){
            m[x[1]].insert(x[0]);
        }
        
        for(auto it = m.begin();it!= m.end();it++){
            if(it->first == 0){
                for(int x: it->second){
                    l.push_back({x,it->first});
                }
            }else{
                for(int x: it->second){
                    fillList(l,it->first,x);
                }
            }
        }
        for(auto x: l){
            ans.push_back(x);
        }
        return ans;
    }
};