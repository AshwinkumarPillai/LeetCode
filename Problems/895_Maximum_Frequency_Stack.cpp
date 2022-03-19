class FreqStack {
public:
    
    map<int, int> freq; // freq of each integer
    map<int, stack<int>> m; // freq -> stack (map of frequency to stack)
    int maxFreq = 0; // curr max freq
    
    FreqStack() {
        maxFreq = 0;
    }
    
    void push(int val) {
        freq[val]++; // increment freq of val
        m[freq[val]].push(val); // push the val to top of corresponding frequency
        maxFreq = max(maxFreq, freq[val]);
    }
    
    int pop() {
        int ans = m[maxFreq].top();
        freq[ans]--;
        m[maxFreq].pop();
        if(m[maxFreq].empty()) maxFreq--; // if there are noo values left of maxFreq then decrease maxFreq
        return ans;
    }
};
