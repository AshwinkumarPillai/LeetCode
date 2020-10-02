// Iterative method
class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int>ans;
        stack<TreeNode*>s1;stack<TreeNode*>s2;
        while(root1 || root2 || !s1.empty() || !s2.empty()){
            while(root1){
                s1.push(root1);
                root1 = root1->left;
            }
            while(root2){
                s2.push(root2);
                root2 = root2->left;
            }
            if(s2.empty() || (!s1.empty() && s1.top()->val <= s2.top()->val)){
                root1 = s1.top();s1.pop();
                ans.push_back(root1->val);
                root1 = root1->right;
            }else{
                root2 = s2.top();s2.pop();
                ans.push_back(root2->val);
                root2 = root2->right;
            }
        }
        return ans;
    }
};


// Recursive dfs and merging two sorted list
class Solution {
public:  
    void dfs(TreeNode* root,vector<int>&v){
        if(!root) return;
        dfs(root->left,v);
        v.push_back(root->val);
        dfs(root->right,v);
    }
    
    void mergeSortedList(vector<int>&a,vector<int>&b,vector<int>&ans){
        int m = a.size(),n = b.size();
        int i=0,j=0;
        while(i<m && j<n){
            if(a[i] < b[j]) ans.push_back(a[i++]);
            else ans.push_back(b[j++]);
        }
        while(i<m) ans.push_back(a[i++]);
        while(j<n) ans.push_back(b[j++]);
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int>ans;
        vector<int>a;vector<int>b;
        dfs(root1,a);
        dfs(root2,b);
        mergeSortedList(a,b,ans);
        return ans;
    }
};

// Recursive dfs and nlogn sort
class Solution {
public:
    
    void dfs(TreeNode* root,vector<int>&v){
        if(!root) return;
        dfs(root->left,v);
        v.push_back(root->val);
        dfs(root->right,v);
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int>ans;
        dfs(root1,ans);
        dfs(root2,ans);
        sort(ans.begin(),ans.end());
        return ans;
    }
};
