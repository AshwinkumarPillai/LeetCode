// O(N) time O(1) space
// Iterate the array. Here the nums in array are between 1 to n inclusive,
// where n is the size of the array. So index = 1-1 to n-1: 0 to n-1.
// So if we negate the integer at an index i, it will be negated twice if it is a duplicate.
// So the index duplicate integers will be positive. So we can add them to ans in second pass
// Also once we encouter the duplicate and add to array negate it again so that we dont add the other duplicate again to ans
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>ans;
        for(int x: nums) nums[abs(x) - 1] *= -1;
        for(int x: nums){
            if(nums[abs(x) - 1] > 0){
                ans.push_back(abs(x));
                nums[abs(x) - 1] *= -1;
            }
        }
        return ans;
    }
};

// O(NlogN) Time O(1) space - using sort
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>ans;
        sort(nums.begin(),nums.end());
        for(int i=1;i<(int)nums.size();i++) if(nums[i] == nums[i-1]) ans.push_back(nums[i]);
        return ans;
    }
};

// O(N) Time and space using map
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>ans;
        unordered_map<int,int>m;
        for(int x: nums) if(++m[x] == 2) ans.push_back(x);
        return ans;
    }
};
