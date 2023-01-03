// Matrix Traversal - O(1) Space
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int k = strs[0].size();
        int ans = 0;
        if(n == 1) return 0;
        for(int i = 0; i < k; i++){
            for(int j = 1; j<n; j++){
                if(strs[j][i] < strs[j-1][i]){
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};


// My Initial Solution
// Store the latest letter in integer form at each index representing respective columns
// Check if the current letter is lower than the previous if yes we need to remove this column
// just increment the column count to be deleted.
// -1 if initial push. -2 to mark column as removed.
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        vector<int> arr(strs[0].length(), -1);
        int ans = 0;
        for(string s: strs){
            for(int i = 0; i < s.length(); i++){
                if(arr[i] == -2) continue;
                else if(arr[i] == -1) arr[i] = s[i] - 'a';
                else{
                    if(arr[i] > (s[i] - 'a')){
                        arr[i] = -2;
                        ans++;
                    }
                    else{
                        arr[i] = s[i] - 'a';
                    }
                }
            }
        }
        return ans;
    }
};
