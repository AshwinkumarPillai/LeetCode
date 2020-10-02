// Global array - precomputation - No sort - O(1) time & space = best solution
vector<int>arr;
class Solution {
public:
    void generateArray(){
        string s = "123456789";
        int len = 1;
        while((len++) < 10)
            for(int i=0;i<9;i++) if(i+len <= 9) arr.push_back(stoi(s.substr(i,len)));    
    }
    
    vector<int> sequentialDigits(int low, int high) {
        if(!arr.size()) generateArray();
        vector<int>ans;
        for(int x: arr) if(x>= low && x<=high) ans.push_back(x);
        return ans;
    }
};

// Global array - precomputation one time sort
vector<int>arr;
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        if(!arr.size()){
            for(int i=1;i<10;i++){
                arr.push_back(i);
                int num = i;
                for(int j=i+1;j<10;j++){
                    num *= 10;
                    num += j;
                    arr.push_back(num);
                }
            }
            sort(arr.begin(),arr.end());
        }
        vector<int>ans;
        for(int x: arr){
            if(x>= low && x<=high) ans.push_back(x);
        }
        return ans;
    }
};
