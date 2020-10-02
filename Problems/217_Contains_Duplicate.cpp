// Sorting
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i=0;i<n-1;i++){
            if(nums[i] == nums[i+1]) return true;
        }
        return false;
    }
};

// using set(like map)
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int>s;
        for(int x: nums){
            if(s.count(x)) return true;
            s.insert(x);
        }
        return false;
    }
};

// using set - remove dup check size
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int>s;
        for(int x: nums) s.insert(x);
        return s.size() < nums.size();
    }
};
