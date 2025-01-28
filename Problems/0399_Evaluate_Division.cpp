// Advanced Data Structures - UNION FIND AND PATH FINDING

// GRAPH IMPLEMENTATION - Path Finding
// Storing values in graph
// Variables as NODE
// Their values as weight
// And direction is maintained as we assign reciprocal of value as weight for the backward path
class Solution {
public:
    
    double dfs(unordered_map<string,unordered_map<string,double>>& m, string& curr, string& target, double curr_prod, set<string>& vis){
        vis.insert(curr);
        double ans = -1.0;  // Initialise ans with -1
        unordered_map<string,double> neighbors = m[curr];
        if(neighbors.find(target) != neighbors.end()){
            ans = curr_prod * neighbors[target];  // if target can be reached from this node calc ans
        }else{
            for(auto p: neighbors){
                string nextNode = p.first;
                if(vis.find(nextNode) == vis.end()){
                    ans = dfs(m,nextNode,target,curr_prod * p.second,vis);
                    if(ans != -1) break; // if target node was reached break the loop
                }
            }
        }
        vis.erase(curr);
        return ans;
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = equations.size();
        unordered_map<string,unordered_map<string,double>>m;
        // Generate Graph
        for(int i=0;i<n;i++){
            vector<string> x = equations[i];
            string num = x[0],deno = x[1];
            double val = values[i];
            m[num][deno] = val;
            m[deno][num] = 1/val;
        }
        // DFS - Perform queries
        vector<double> ans;
        for(auto x: queries){
            string num = x[0], deno = x[1];
            if(m.find(num) == m.end() || m.find(deno) == m.end()) 
                ans.push_back(-1.0);  // Variable doesn't exists
            else if(num == deno) 
                ans.push_back(1.0);  // x/x = 1
            else{
                set<string>vis;
                double val = dfs(m,num,deno,1,vis);
                ans.push_back(val);
            }
        }
        return ans;
    }
};

// Union Find
// Coming Soon(Probably Nov)

