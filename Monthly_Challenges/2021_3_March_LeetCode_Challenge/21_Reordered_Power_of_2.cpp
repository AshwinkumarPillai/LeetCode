class Solution {
public:
    bool reorderedPowerOf2(int N) {
        string n = to_string(N);
        sort(n.begin(),n.end());
        for(int i=0;i<32;i++){
            string n2 = to_string(1<<i);
            sort(n2.begin(),n2.end());
            if(n == n2) return true;
        }
        return false;
    }
};
