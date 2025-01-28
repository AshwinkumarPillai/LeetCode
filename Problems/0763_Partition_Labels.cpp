class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char,int>m;
        vector<int>ans;
        int n = s.length();
        for(int i=0;i<n;i++) m[s[i]] = i;
        int last = 0,start = 0;
        for(int i=0;i<n;i++){
            last = max(last,m[s[i]]);
            if(i == last){
                ans.push_back(i-start+1);
                start = i+1;
            }
        }
        return ans;
    }
};
