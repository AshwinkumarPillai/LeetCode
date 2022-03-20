class Solution {
public:
    
    bool satisfy(vector<int>&tops, vector<int>& bottoms, int val, int n){
        for(int i=0;i<n;i++){
            if(tops[i] != val && bottoms[i] != val) return false;
        }
        return true;
    }
    
    int numRotations(vector<int>& arr, int val){
        int ans = 0;
        for(int x: arr) if(x != val) ans++;
        return ans;
    }
    
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        
        int ans = -1;
        
        if(satisfy(tops, bottoms, tops[0], n)) {
            ans = min(numRotations(tops, tops[0]), numRotations(bottoms, tops[0]));
        }
        if(satisfy(tops, bottoms, bottoms[0], n)) {
            int x = min(numRotations(bottoms, bottoms[0]), numRotations(tops, bottoms[0]));
            ans = ans == -1 ? x : min(ans, x);
        }
        
        return ans;
    }
};
