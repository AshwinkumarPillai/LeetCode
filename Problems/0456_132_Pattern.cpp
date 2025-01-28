// O(N) - Time | O(1) Space
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return false;
        int top = n, third = INT_MIN;
        
        for(int i = n - 1; i>=0; i--){
            if(nums[i] < third) return true;
            while(top < n && nums[i] > nums[top]) third = nums[top++];
            nums[--top] = nums[i];
        }
        return false;
    }
};

// Using Stack | O(N) - Time | O(N) - Space
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int s3 = INT_MIN;
        stack<int> st;
        for( int i = nums.size()-1; i >= 0; i -- ){
            if( nums[i] < s3 ) return true;
            else while( !st.empty() && nums[i] > st.top() ){ 
              s3 = st.top(); st.pop(); 
            }
            st.push(nums[i]);
        }
        return false;
    }
};

// Time - O(n2) - TLE
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return false;
        
        for(int j = 0, minVal = INT_MAX; j< n;j++){
            minVal = min(nums[j], minVal);
            if(minVal == nums[j]) continue;
            
            for(int k = n - 1; k > j; k--){
                if(nums[k] > minVal && nums[k] < nums[j]) return true;
            }
        }
        return false;
    }
};
