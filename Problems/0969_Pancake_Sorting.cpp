// With cpp built-ins
class Solution {
public:    
    vector<int> pancakeSort(vector<int>& A) {
        vector<int>ans;
        int n = A.size();
        for(int i=n;i>0;i--){
            auto it = max_element(A.begin(),A.begin()+i);
            int index = it-A.begin() + 1;
            if(index != i){
                if(index != 1){
                    ans.push_back(index);
                    reverse(A.begin(),A.begin()+index);
                }
                ans.push_back(i);
                reverse(A.begin(),A.begin()+i);

            }
        }
        return ans;
    }
};

// Without built-ins
class Solution {
public:
    
    int findCurrMax(vector<int>& A,int val,int n){
        for(int i=0;i<n;i++) if(A[i] == val) return i;
        return -1;
    }
    
    void flip(vector<int>& A,int index){
        int i = 0;
        while(i<index/2){
            swap(A[i],A[index-i-1]);
            i++;
        }
    }
    
    vector<int> pancakeSort(vector<int>& A) {
        vector<int>ans;
        int n = A.size();
        for(int i=n;i>0;i--){
            int index = findCurrMax(A,i,n);
            if(index != i-1){
                if(index != 0){
                    ans.push_back(index+1);
                    flip(A,index+1);
                }
                ans.push_back(i);
                flip(A,i);
            }
        }
        return ans;
    }
};
