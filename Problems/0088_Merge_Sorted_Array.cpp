//IN-PLACE SORT O(N) - TIME | O(1) - SPACE
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1, j = n-1, k = m+n-1;
        while(i>=0 && j >=0){
            if(nums1[i] > nums2[j]) nums1[k--] = nums1[i--];
            else nums1[k--] = nums2[j--];
        }
        
        while(j>=0) nums1[k--] = nums2[j--];
    }
};

// Extra Space solution - Naive
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0, j = 0, k = 0;
        vector<int> nums = nums1;
        while(i < m && j < n){
            if(nums[i] < nums2[j]) nums1[k++] = nums[i++];
            else if(nums[i] == nums2[j]){
                nums1[k++] = nums[i++];
                nums1[k++] = nums2[j++];
            }else nums1[k++] = nums2[j++];
        }
        
        while(i<m) nums1[k++] = nums[i++];
        while(j<n) nums1[k++] = nums2[j++];
    }
};