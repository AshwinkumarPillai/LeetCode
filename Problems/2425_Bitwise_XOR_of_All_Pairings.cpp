class Solution
{
public:
    int xorAllNums(vector<int> &nums1, vector<int> &nums2)
    {
        int ans = 0;
        if (nums1.size() % 2 == 1)
            for (int x : nums2)
                ans ^= x;
        if (nums2.size() % 2 == 1)
            for (int x : nums1)
                ans ^= x;
        return ans;
    }
};