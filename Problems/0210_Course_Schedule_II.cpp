class Solution {
public:
    
    bool checkCycle(int i,unordered_map<int,vector<int>>& g, vector<int>& vis){
        if(vis[i] == 1)return true;
        else if(vis[i] == 2) return false;
        vis[i] = 1;
        for(int x: g[i]) if(checkCycle(x,g,vis)) return true;
        vis[i] = 2;
        return false;
    }
    
    bool detectCycle(unordered_map<int,vector<int>>& g,int n){
        vector<int>vis(n);
        for(auto x: g){
            if(!vis[x.first] && checkCycle(x.first,g,vis)) return true;
        }
        return false;
    }
    
    void dfs(unordered_map<int,vector<int>>& g,vector<int>& vis,vector<int>& ans,int i){
        if(vis[i]) return;
        vis[i] = 1;
        for(int x: g[i]){
            dfs(g,vis,ans,x);
        }
        ans.push_back(i);
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        if(numCourses == 0) return {};
        if(numCourses == 1) return {0};
        unordered_map<int,vector<int>>graph;
        for(auto v : prerequisites){
            graph[v[1]].push_back(v[0]);
        }
        
        if(detectCycle(graph,numCourses)) return {};
        vector<int>ans;
        vector<int>vis(numCourses);
        for(int i=0;i<numCourses;i++){
            dfs(graph,vis,ans,i);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
