class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size(),ans = 0;
        int left = 0,right = n-1;
        while(left+1< n && arr[left] <= arr[left+1]) left++;
        if(left == n-1) return 0;
        while(right>left && arr[right-1] <= arr[right]) right--;
        ans = min(n-left-1,right);
        int i=0,j=right;
        while(i<=left && j<n){
            if(arr[j] >= arr[i]) ans = min(ans,j - 1 - i++);
            else j++;
        }
        return ans;
    }
};

// -----------=right
//           -------=n-left-1
// [1,2,3,10,4,2,3,5]
//         ^   ^right      
//         left
        
