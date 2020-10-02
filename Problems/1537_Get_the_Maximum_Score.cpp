class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        long long i =0,j=0,m=nums1.size(),n=nums2.size(),mp=1e9+7,a=0,b=0,xa=0,xb=0,maxval;
        while(i<m && j<n){
            if(nums1[i] < nums2[j]) a+= nums1[i++];
            else if(nums1[i] > nums2[j]) b+= nums2[j++];
            else{
                maxval = max(xa + nums1[i], xb + nums2[j]);
                a = b = maxval;
                i++;j++;
            } 
            xa = a;xb=b;
        }
        while(i<m) a += nums1[i++];
        while(j<n) b += nums2[j++];
        return max(a,b) % mp;
    }
};
