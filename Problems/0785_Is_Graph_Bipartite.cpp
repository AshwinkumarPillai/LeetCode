// Graph Coloring - DFS
class Solution {
public:
    
    bool dfs(vector<vector<int>>& graph, int i, vector<bool>& visited, vector<int>& color, int currColor){
        visited[i] = true;
        color[i] = currColor;
        
        for(int v: graph[i]){
            if(!visited[v]) {
                if(!dfs(graph, v, visited, color, currColor ^ 1)) return false;
            }else{
                if(color[i] == color[v]) return false;
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> visited(n, false);
        vector<int>color(n);
       
        for(int i=0;i<n;i++){
            if(!visited[i] && !dfs(graph, i, visited, color, 0)) return false;
        }
        
        return true;
    }
};