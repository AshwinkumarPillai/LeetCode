// Same as mine but neater and the real DUTCH NATIONAL FLAG algorithm
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int i = 0, j = i, k = nums.size() - 1;

        while (j <= k)
        {
            if (nums[j] == 0)
                swap(nums[i++], nums[j++]);
            else if (nums[j] == 1)
                j++;
            else
                swap(nums[k--], nums[j]);
        }
    }
};

// My optimised solution but not be used.
class Solution
{
public:
    void swap(vector<int> &arr, int i, int j)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    void correct(vector<int> &nums, int &i, int &k)
    {
        while (i + 1 < nums.size() && nums[i + 1] == 0)
        {
            i++;
        }
        while (k - 1 >= 0 && nums[k - 1] == 2)
        {
            k--;
        }
    }

    void sortColors(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1 || n == 0)
        {
            return;
        }
        int i = -1, j, k = n;
        correct(nums, i, k);
        j = i + 1;
        while (j < k)
        {
            if (nums[j] == 2)
            {
                swap(nums, j, k - 1);
                correct(nums, i, k);
            }
            else if (nums[j] == 0)
            {
                swap(nums, j, i + 1);
                correct(nums, i, k);
            }
            j = i + 1;
            while (j < n && nums[j] == 1)
            {
                j++;
            }
            if (j == n)
            {
                break;
            }
        }
    }
};