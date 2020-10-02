class Solution {
public:
    bool isValid(vector<int>&position,int mid,int m){
        int prev = 0;
        for (int i = 1, j = 1; i < m; i++) {
            while (j < position.size() && position[j] < position[prev] + mid) j++;
            if (j >= position.size()) return false;
            prev = j;
        }
        return true;
    }
    
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        if(m == 2) return position.back() - position[0];
        int left = 1,right = position.back() - position[0];
        while(left<=right){
            int mid = (left+right)/2;
            if(isValid(position,mid,m)) left = mid+1;
            else right = mid - 1;
        }
        return right;
    }
};
