class Solution {
public:
    void fillpath(vector<vector<int>>&graph, int i,int target,vector<vector<int>>& ans,vector<int>t){
        t.push_back(i);
        if(i == target) ans.push_back(t);
        for(int x: graph[i]) fillpath(graph,x,target,ans,t);
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>ans;
        int target = graph.size()-1;
        fillpath(graph,0,target,ans,{});
        return ans;
    }
};
