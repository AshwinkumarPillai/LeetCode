// Single Pass - No extra Space solution
// O(n) - Time | O(1) - Space
class Solution
{
public:
    bool canChange(string start, string target)
    {
        int n = start.length();
        int sIndex = 0, tIndex = 0;

        while (sIndex < n || tIndex < n)
        {
            while (sIndex < n && start[sIndex] == '_')
                sIndex++;
            while (tIndex < n && target[tIndex] == '_')
                tIndex++;

            if (sIndex == n || tIndex == n)
                return sIndex == tIndex;

            if (start[sIndex] != target[tIndex])
                return false;

            if ((target[tIndex] == 'L' && sIndex < tIndex) || (target[tIndex] == 'R' && sIndex > tIndex))
                return false;

            sIndex++;
            tIndex++;
        }

        return sIndex == tIndex;
    }
};

// Map the indices and check the order -  with extra space to store the mapping (Not Effecient)
class Solution
{
public:
    bool canChange(string start, string target)
    {
        vector<pair<char, int>> p;
        int n = start.length();

        for (int i = 0; i < n; i++)
        {
            if (start[i] != '_')
            {
                p.push_back({start[i], i});
            }
        }

        int index = 0, m = p.size();
        for (int i = 0; i < n; i++)
        {
            char x = target[i];
            if (x != '_')
            {
                if (index == m)
                    return false;
                if (x == 'L')
                {
                    if ((p[index].first == 'L' && p[index].second < i) || (p[index].first == 'R'))
                    {
                        return false;
                    }
                }
                if (x == 'R')
                {
                    if ((p[index].first == 'R' && p[index].second > i) || (p[index].first == 'L'))
                    {
                        return false;
                    }
                }
                index++;
            }
        }

        return index == m;
    }
};