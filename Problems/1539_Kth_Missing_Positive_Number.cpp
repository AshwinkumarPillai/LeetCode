class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int num = 1,i=0,n = arr.size();
        if(!n) return k;
        while(i<n){
            if(arr[i] != num){
                if(--k == 0) return num;
            }else{
                i++;
            }
            num++;
        }
        while(--k) num++;
        return num;
    }
};
