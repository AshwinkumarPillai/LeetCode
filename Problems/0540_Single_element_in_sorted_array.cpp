class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int ans = -1, n = nums.size(), start = 0, end = n - 1;
        if (n == 1)
        {
            return nums[0];
        }
        if (nums[start] != nums[start + 1])
        {
            return nums[start];
        }
        if (nums[end] != nums[end - 1])
        {
            return nums[end];
        }
        int mid;
        while (start <= end)
        {
            mid = start + (end - start) / 2;
            if (mid % 2 != 0)
            {
                if (nums[mid] == nums[mid - 1])
                {
                    start = mid + 1;
                }
                else
                {
                    if (nums[mid] == nums[mid + 1])
                    {
                        end = mid - 1;
                    }
                    else
                    {
                        return nums[mid];
                    }
                }
            }
            else
            {
                if (nums[mid] == nums[mid + 1])
                {
                    start = mid + 2;
                }
                else
                {
                    if (nums[mid] == nums[mid - 1])
                    {
                        end = mid - 2;
                    }
                    else
                    {
                        return nums[mid];
                    }
                }
            }
        }
        return nums[n - 1];
    }
};