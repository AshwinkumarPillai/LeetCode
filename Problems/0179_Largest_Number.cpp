class Solution {
public:
    static bool compare(string a,string b){
        return (a+b) > (b+a);
    }
    string largestNumber(vector<int>& nums) {
        if(!nums.size()) return "";
        vector<string>arr;
        for(int x: nums) arr.push_back(to_string(x));
        sort(arr.begin(),arr.end(),compare);
        string ans = "";
        if(arr[0] == "0") return "0";
        for(string x: arr) ans += x;
        return ans;
    }
};
