class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {

        int n = nums1.size();
        int m = nums2.size();

        vector<int> res(m + n);

        merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), res.begin());

        sort(res.begin(), res.end());

        int l = 0;
        int h = res.size() - 1;
        int mid = (l + h) / 2;
        if ((h + 1) % 2 == 0)
        {
            double ans = (1.0 * res[mid] + 1.0 * res[mid + 1]) / 2;
            return ans;
        }

        return 1.0 * res[mid];
    }
};