// O(log(n)) solution - Binary search
class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int n = nums.size();
        if (target <= nums[0])
        {
            return 0;
        }
        else if (target >= nums[n - 1])
        {
            return (target == nums[n - 1]) ? n - 1 : n;
        }
        int low = 0, high = n - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int x = nums[mid];
            if (x == target)
            {
                return mid;
            }
            else if (x > target)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return low;
    }
};

// O(n) solution
class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int n = nums.size();
        if (target <= nums[0])
        {
            return 0;
        }
        else if (target >= nums[n - 1])
        {
            return (target == nums[n - 1]) ? n - 1 : n;
        }
        int index = 0;
        while (target > nums[index++])
        {
        }
        return index - 1;
    }
};