/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */


// Flatten via Recursion - Space - O(N) | Time - O(N)
class NestedIterator {
public:
    
    vector<int> ans;
    int i = 0;
    int n;
    
    void flatten(vector<NestedInteger> &nl){
        for(auto x: nl){
            if(x.isInteger()){
                ans.push_back(x.getInteger());
            }else{
                flatten(x.getList());
            }
        }
    }
    
    NestedIterator(vector<NestedInteger> &nestedList) {
        flatten(nestedList);
        n = ans.size();
    }
    
    int next() {
        return ans[i++];
    }
    
    bool hasNext() {
        return i < n;
    }
};


// Using Stack | Time - O(N) | Space - O(N)
class NestedIterator {
public:
    
    stack<NestedInteger> st;
    
    void fillStack(vector<NestedInteger> &nl){
        int n = nl.size();
        for(int i = n-1; i>=0;i--){
            st.push(nl[i]);
        }
    }
    
    NestedIterator(vector<NestedInteger> &nestedList) {
        fillStack(nestedList);
    }
    
    int next() {
        int ans = st.top().getInteger();
        st.pop();
        return ans;
    }
    
    bool hasNext() {
        while(!st.empty()){
            auto curr = st.top();
            if(curr.isInteger()) return true;
            
            st.pop();
            fillStack(curr.getList());
        }
        return false;
    }
};


/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */