// DFS
class Solution {
public:

    int dfs(vector<vector<int>>& adj, int curNode,int parent, string& labels, vector<int>& pathVal){
        int longestPath = 1;
        vector<int>childPaths;
        for(int child: adj[curNode]){
            if(child == parent) continue;
            int childLongestPath = dfs(adj, child, curNode, labels, pathVal);
            if(labels[curNode] != labels[child]) childPaths.push_back(childLongestPath);
        }
        sort(childPaths.begin(), childPaths.end(), greater<int>());
        int len = childPaths.size();
        if(len == 1) longestPath = 1 + childPaths[0];
        else if(len > 1) longestPath = 1 + childPaths[0] + childPaths[1];
        pathVal[curNode] = longestPath;
        if(len == 0) return 1;
        return 1 + childPaths[0];
    }

    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        vector<int> pathVal(n);
        int ans = 0;
        vector<vector<int>> adj(n);
        for(int i = 1; i < n; i++){
            adj[i].emplace_back(parent[i]);
            adj[parent[i]].emplace_back(i);
        }
        dfs(adj, 0, -1, s, pathVal);
        for(int x: pathVal) ans = max(ans, x);
        return ans;
    }
};