class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& f, int s, int d, int K) {
        map<int,vector<vector<int>>>m;
        for(auto x: f){
            m[x[0]].push_back({x[1],x[2],0});
        }
        
        queue<vector<int>>q;
        q.push({s,0,-1});
        int ans = INT_MAX;
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            if(node[0] == d){
                ans = min(ans,node[1]);
            }else{
                for(auto x: m[node[0]]){
                    int newCost = node[1]+x[1];
                    int k = node[2];
                    if(k+1 <= K && newCost < ans){
                        q.push({x[0],newCost,k+1});
                    }
                }                
            }
        }
        return (ans != INT_MAX) ? ans : -1;
    }
};