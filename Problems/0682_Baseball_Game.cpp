class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int>arr;
        
        for(string x: ops){
            if(x == "C"){
                arr.pop_back();
            }else if(x == "D"){
                arr.push_back(arr.back() * 2);
            }else if(x == "+"){
                int n = arr.size();
                arr.push_back(arr[n-1] + arr[n-2]);
            }else{
                arr.push_back(stoi(x));
            }
        }
        
        return accumulate(arr.begin(), arr.end(), 0);
    }
};
