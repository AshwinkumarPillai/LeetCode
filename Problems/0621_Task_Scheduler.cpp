class Solution {
public:

    int leastInterval(vector<char>& tasks, int n) {
        int ans = tasks.size();
        if(!n) return ans;
        vector<int>freq(26);
        for(char x: tasks) freq[x-'A']++;
        sort(freq.begin(),freq.end());
        int maxval = freq[25] - 1;
        int idle = maxval*n;
        for(int i=24;i>=0;i--) idle-= min(maxval,freq[i]);
        ans+= max(0,idle);
        return ans;
    }
};
