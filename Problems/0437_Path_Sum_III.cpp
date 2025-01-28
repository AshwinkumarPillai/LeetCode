// Using prefix sum and map (subarray sum equals k for tree)
class Solution {
public:
    int ans = 0;
    void dfs(map<int,int>& m,TreeNode* root,int csum,int k){
        if(!root) return;
        csum += root->val;
        if(csum == k) ans++;
        if(m.find(csum - k) != m.end()) ans += m[csum - k];
        if(m.find(csum) != m.end()) m[csum]++;
        else m[csum] = 1;
        dfs(m,root->left,csum,k);
        dfs(m,root->right,csum,k);
        m[csum]--;
    }
    
    int pathSum(TreeNode* root, int sum) {
        map<int,int>m;
        dfs(m,root,0,sum);
        return ans;
    }
};

// O(n) space solution - by keeping track of all values of  path sums for children
class Solution {
public:
    int count = 0;
    vector<int> dfs(TreeNode* root,int sum){
        if(!root) return {};
        int val = root->val;
        vector<int>all;
        vector<int>l = dfs(root->left,sum);
        for(int i=0;i<(int)l.size();i++){
            if(val + l[i] == sum) count++;
            all.push_back(val+l[i]);
        }
        vector<int>r = dfs(root->right,sum);
        for(int i=0;i<(int)r.size();i++){
            if(val + r[i] == sum) count++;
            all.push_back(val+r[i]);
        }
        if(val == sum) count++;
        all.push_back(val);
        return all;
    }
    
    int pathSum(TreeNode* root, int sum) {
        dfs(root,sum);
        return count;
    }
};
