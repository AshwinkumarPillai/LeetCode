class Solution {
public:
    
    TreeNode* createRoot(vector<int>& arr, int start, int end){
        if(start > end) return NULL;
        int mid = (start + end ) / 2;
        TreeNode* root = new TreeNode(arr[mid]);
        root->left = createRoot(arr, start, mid-1);
        root->right = createRoot(arr, mid+1, end);
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return createRoot(nums, 0, nums.size()-1);
    }
};
