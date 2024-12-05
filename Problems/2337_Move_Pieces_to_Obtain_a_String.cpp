// Map the indices and check the order
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