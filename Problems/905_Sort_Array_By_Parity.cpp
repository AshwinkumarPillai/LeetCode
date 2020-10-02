// Using Sort
class Solution {
public:
    static bool compare(int a,int b){
        return !(a % 2) && (b%2);
    }
    
    vector<int> sortArrayByParity(vector<int>& A) {
        sort(A.begin(),A.end(),compare);
        return A;
    }
};

// One Pass in-place
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int n = A.size() - 1;
        for(int i=0;i<n;i++) if(A[i] % 2) swap(A[i--],A[n--]);
        return A;
    }
};

// Two Pass solution
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        vector<int>ans;
        for(int x: A){
            if(!(x&1)) ans.emplace_back(x);
        }
        
        for(int x: A){
            if((x&1)) ans.emplace_back(x);
        }
        return ans;
    }
};

// Quick Sort
class Solution {
    public:
    
    vector<int> sortArrayByParity(vector<int>& A) {
        int i = 0, j = A.size() - 1;
        while (i < j){
            if (A[i] % 2 > A[j] % 2){
                int tmp = A[i];
                A[i] = A[j];
                A[j] = tmp;
            }
            if (A[i] % 2 == 0) i++;
            if (A[j] % 2 == 1) j--;
        }
        return A;
    }
};

