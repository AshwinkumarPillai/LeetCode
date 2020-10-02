class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size();
        auto maxval = max_element(arr.begin(),arr.end());
        if(k>=n-1) return *maxval;
        int count = 0,val = 0,i=0,j=1;
        while(i<n && j<n){
            if(arr[i] > arr[j]){
                if(arr[i] != val) count = 0;
                val = arr[i];
                if(++count == k) return arr[i];
                j++;
            }else if(arr[i] < arr[j]){
                if(arr[j] != val) count = 0;
                val = arr[j];
                if(++count == k) return arr[j];                
                i = j;
                j = i+1;
            }
        }
        return *maxval;
    }
};
