// Sliding Window
// Time - O(n) | Space - O(1)

class Solution
{
public:
    int totalFruit(vector<int> &fruits)
    {
        int max_size = 0;
        int i = 0, j = 0, n = fruits.size();
        map<int, int> m;

        while (j < n)
        {
            m[fruits[j]]++;

            while (m.size() > 2)
            {
                m[fruits[i]]--;
                if (m[fruits[i]] == 0)
                    m.erase(fruits[i]);
                i++;
            }
            max_size = max(max_size, j - i + 1);
            j++;
        }
        return max_size;
    }
};