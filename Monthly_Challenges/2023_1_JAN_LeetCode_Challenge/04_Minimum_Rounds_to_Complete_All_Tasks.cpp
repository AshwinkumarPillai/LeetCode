class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        map<int, int>m;
        int ans = 0;
        for(int task: tasks){
            m[task]++;
        }

        for(auto p: m){
            if(p.second < 2) return -1;
            int x = p.second % 3;
            if(x == 0) ans += p.second / 3; // divide into groups of 3
            // If x = 1; (count / 3 - 1) groups of triplets and 2 pairs.
            // If x = 2; (count / 3) groups of triplets and 1 pair.
            else ans += (p.second / 3) + 1; 
        }
        return ans;
    }
};