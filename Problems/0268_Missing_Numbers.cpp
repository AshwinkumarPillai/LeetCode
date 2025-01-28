// Math -- Guass formula (sum of first n numbers)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = (n*(n+1))/2;
        for(int x:nums) sum -= x;
        return sum;
    }
};

// Bit Manip  --- XOR
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size(),xr=0;
        for(int i=0;i<n;i++){
            xr ^= i;
            xr ^= nums[i];
        }
        xr ^= n;
        return xr;
    }
};

// Using Set
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int>s;
        for(int x: nums) s.insert(x);
        for(int i=0;i<n;i++){
            if(s.find(i) == s.end()) return i;
        }
        return n;
    }
};


// Sorting
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(nums[i] != i) return i;
        }
        return n;
    }
};
