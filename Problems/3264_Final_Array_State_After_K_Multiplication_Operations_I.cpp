// HEAP
class Solution
{
public:
    vector<int> getFinalState(vector<int> &nums, int k, int multiplier)
    {
        vector<pair<int, int>> heap;
        for (int i = 0; i < nums.size(); i++)
        {
            heap.push_back({nums[i], i});
        }

        make_heap(heap.begin(), heap.end(), greater<>());

        while (k--)
        {
            pop_heap(heap.begin(), heap.end(), greater<>());
            auto [value, i] = heap.back();
            heap.pop_back();

            nums[i] *= multiplier;
            heap.push_back({nums[i], i});
            push_heap(heap.begin(), heap.end(), greater<>());
        }

        return nums;
    }
};

class Solution
{
public:
    vector<int> getFinalState(vector<int> &nums, int k, int multiplier)
    {
        priority_queue<pair<int, int>> heap;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            heap.push({-1 * nums[i], -1 * i});
        }

        while (k-- > 0)
        {
            int val = -1 * heap.top().first;
            int index = -1 * heap.top().second;
            heap.pop();
            int newVal = val * multiplier;
            nums[index] = newVal;
            heap.push({-1 * newVal, -1 * index});
        }

        return nums;
    }
};