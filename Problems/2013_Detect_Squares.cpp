class DetectSquares
{
public:
    map<pair<int, int>, int> points;

    DetectSquares()
    {
    }

    void add(vector<int> point)
    {
        points[{point[0], point[1]}] += 1;
    }

    int count(vector<int> point)
    {
        int ans = 0;
        for (auto &p : points)
        {
            pair<int, int> diag = p.first;
            if (abs(diag.first - point[0]) != abs(diag.second - point[1]) || point[0] == diag.first || point[1] == diag.second)
            {
                continue;
            }
            ans += (getValue({diag.first, point[1]}) * getValue({point[0], diag.second}) * getValue({diag.first, diag.second}));
        }
        return ans;
    }

    int getValue(pair<int, int> p)
    {
        if (points.find(p) == points.end())
            return 0;
        return points[p];
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */