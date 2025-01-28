class Solution {
    int kadane(vector<int>& A,int n){
        int cmax = A[0];
        int gmax = A[0];
        for(int i=1;i<n;i++){
            cmax = max(A[i],A[i] + cmax);
            if(cmax>gmax){
                gmax = cmax;
            }
        }
        return gmax;
    }
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int n = A.size();
        if(n == 1){
            return A[0];
        }
        int gmax = kadane(A,n);
        int csum = 0;
        for(int i =0 ;i<n;i++){
            csum+=A[i];
            A[i] = -A[i];
        }
        int ngmax = kadane(A,n);
        csum+=ngmax;
        if(csum == 0){
            return gmax;
        }
        return max(csum,gmax);
        
    }
};