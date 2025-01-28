class Solution {
public:
    
    vector<int>pref;
    int n;
    Solution(vector<int>& w) {
        n = w.size();
        pref.emplace_back(w[0]);
        for(int i=1;i<n;i++){
            pref.emplace_back(pref.back() + w[i]);
        }
    }
    
    int bins(int r){
        int low = 0,high = n,mid;
        while(low<=high){
            mid = low + (high-low) / 2;
            if(r > pref[mid]){
                low = mid+1;
            }
            else{
                high = mid - 1;
            }
        }
        return low;
    }
    
    int pickIndex() {
        int r = rand() % pref[n-1] + 1;
        return bins(r);
    }
};