class Solution {
public:
    static bool compare(vector<int>& a, vector<int>&b){
        return (a[0]*a[0] + a[1]*a[1]) < (b[0]*b[0] + b[1]*b[1]);
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        sort(points.begin(),points.end(),compare);
        points.resize(k);
        return points;
        map<int,vector<vector<int>>>m;
        for(auto x: points){
            int dist = x[0]*x[0] + x[1]*x[1];
            m[dist].push_back(x);
        }
        
        vector<vector<int>> ans;
        for(auto p:m){
            for(auto x: p.second){
                ans.push_back(x);
                if((--k) == 0){
                    return ans;
                }
            }
        }
        return ans;
    }
};    
//     vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
//         map<int,vector<vector<int>>>m;
//         for(auto x: points){
//             int dist = x[0]*x[0] + x[1]*x[1];
//             m[dist].push_back(x);
//         }

//         vector<vector<int>> ans;
//         for(auto p:m){
//             for(auto x: p.second){
//                 ans.push_back(x);
//                 if((--k) == 0){
//                     return ans;
//                 }
//             }
//         }
//         return ans;
//     }
