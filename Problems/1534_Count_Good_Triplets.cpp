class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int n = arr.size(),ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int x = arr[i],y = arr[j];
                if(abs(x-y)>a) continue;
                for(int k=j+1;k<n;k++){
                    int z = arr[k];
                    if((abs(y-z) <= b) && (abs(x-z) <=c)) ans++;
                }
            }
        }
        return ans;
    }
};
