class Solution {
public:
    double r;
    double x,y;
    Solution(double radius, double x_center, double y_center) {
        r = radius;x = x_center;y=y_center;
    }
    
    vector<double> randPoint() {
         double theta = (double)rand() / RAND_MAX * 2 * M_PI,
            hyp = sqrt((double)rand() / RAND_MAX) * r,
            adj = cos(theta) * hyp,
            opp = sin(theta) * hyp;
        return vector<double>{x + adj, y + opp};
    }
};
