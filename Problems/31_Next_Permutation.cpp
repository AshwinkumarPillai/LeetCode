// Fastest
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return;
        int i = n-2;
        while(i>=0 && nums[i] >= nums[i+1]) i--;
        if(i == -1) reverse(nums.begin(),nums.end());
        else{
            int j = n-1;
            while(j>i && nums[j] <= nums[i]) j--;
            swap(nums[i],nums[j]);
            reverse(nums.begin()+i+1,nums.end());
        }
    }
};

//  With helper functions
class Solution {
public:
    int findFirstDec(vector<int>& nums){
        for(int i = nums.size() -1; i >= 1;i--){
            if(nums[i] > nums[i-1]) return i-1;
        }
        return -1;
    }
    
    int findSecond(vector<int>& nums,int i){
        int j = i,val = nums[i],n = nums.size();
        while(j<n-1 && nums[j+1] > val) j++;
        return j;
    }
    
    void swap(vector<int>& nums,int i,int j){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return;
        if(n == 2) {
            swap(nums,0,1);
            return;
        }
        int firstIndex = findFirstDec(nums);
        if(firstIndex == -1) {
            reverse(nums.begin(),nums.end());
            return;
        }
        int second = findSecond(nums,firstIndex);
        swap(nums,firstIndex,second);
        reverse(nums.begin() + firstIndex+1,nums.end());
    }
};

// Built-in function
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin(),nums.end());
    }
};
