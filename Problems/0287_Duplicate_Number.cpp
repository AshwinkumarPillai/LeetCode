// O(1) space | without array modification - Floyd Tortoise Hare
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        if (nums.size() < 2)
            return -1;
        int slow = nums[0];
        int fast = nums[slow];
        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        fast = 0;
        while (slow != fast)
        {
            fast = nums[fast];
            slow = nums[slow];
        }
        return slow;
    }
};

// O(1) space | O(nlogn) Time | With array modification
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < int(nums.size()); i++)
        {
            if (nums[i] == nums[i - 1])
                return nums[i];
        }
        return -1;
    }
};
