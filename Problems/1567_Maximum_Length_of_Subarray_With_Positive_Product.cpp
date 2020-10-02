class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int i = 0, n = nums.size(), ans = 0;
        while (i < n) {
            int j = i, count = 0, firstNeg = -1, lastNeg = -1;
            while (i < n && nums[i] != 0) {
                count += nums[i] < 0;
                if (nums[i] < 0) {
                    if (firstNeg == -1) firstNeg = i;
                    lastNeg = i;
                }
                i++;
            }
            // ans is max of the prev ans, from the next ele of first negetive num to i, from current i(j) to the last negetive
            if ((count & 1)) ans = max({ ans, i - firstNeg - 1, lastNeg - j });
            else ans = max(ans, i - j);
            while (i < n && nums[i] == 0) i++;
        }
        return ans;
    }
};
