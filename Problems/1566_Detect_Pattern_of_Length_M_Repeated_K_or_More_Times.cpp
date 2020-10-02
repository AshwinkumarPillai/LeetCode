class Solution {
public:
    bool containsPattern(vector<int>& arr, int m, int k) {
        int n = arr.size(),ml = m * k;
        if (n < ml) return false;
        for (int i = 0; i <= n - ml; i++) {
            bool valid = true;
            for (int j = 1; j < k && valid; j++) {
                for (int x = 0; x < m && valid; x++) {
                    if (arr[i + m * j + x] != arr[i + x]) valid = false;
                }
            }
            if (valid) return true;
        }
        return false;
    }
};
