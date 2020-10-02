class Solution {
public:
    
    bool isValid(vector<int>& a){
        int f = a[0]*10 + a[1];
        int l = a[2]*10 + a[3];
        return f>=0 && f<24 && l>=0 && l<60; 
    }
    
    vector<vector<int>> fillPermutations(vector<int>& arr){
        vector<vector<int>>perms;
        sort(arr.begin(),arr.end());
        do{
            cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2]<<" "<<arr[3]<<"\n";
            if(isValid(arr)) perms.push_back(arr);
        }while(next_permutation(arr.begin(),arr.end()));
        if(isValid(arr)) perms.push_back(arr);
        return perms;
    }
    
    static bool compare(vector<int>& a,vector<int>& b){
        int f1 = a[0]*10 + a[1];
        int l1 = a[2]*10 + a[3];
        int f2 = b[0]*10 + b[1];
        int l2 = b[2]*10 + b[3];
        if(f1 > f2) return true;
        else if(f1<f2) return false;
        return l1 > l2;
    }
    
    string largestTimeFromDigits(vector<int>& A) {
        vector<vector<int>> p = fillPermutations(A);
        if(p.size() == 0) return "";
        sort(p.begin(),p.end(),compare);
        string ans = to_string(p[0][0]) + to_string(p[0][1]) + ":" + to_string(p[0][2]) + to_string(p[0][3]);
        return ans;
    }
};
