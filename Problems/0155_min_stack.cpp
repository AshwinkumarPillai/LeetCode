class MinStack {
public:
    
    vector<int>stack;
    vector<int>minVals;
    
    /** initialize your data structure here. */
    MinStack() {
        
    }

    // Memory Effecient - only store min Value if current value is a min val
    void push(int val) {
        stack.push_back(val);
        if(minVals.size()){
            if(val <= minVals.back()) minVals.push_back(val);
        }else minVals.push_back(val);
    }
    
    void pop() {
        if(minVals.back() == stack.back()) minVals.pop_back();
        stack.pop_back();
    }
    
    int top() {
        return stack.back();
    }
    
    int getMin() {
        return minVals.back();
    }
};