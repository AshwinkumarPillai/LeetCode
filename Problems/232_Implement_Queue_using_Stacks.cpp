class MyQueue {
public:
    stack<int> olds;
    stack<int> news;
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    // Helper Functions
    void shiftHelper(){
        if(olds.empty()){
            while(!news.empty()){
                olds.push(news.top());
                news.pop();
            }
        }
    }
    
    int size(){
        return olds.size() + news.size();
    }
    
    // Helper functions end
    
    /** Push element x to the back of queue. */
    void push(int x) {
        news.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int val = peek();
        olds.pop();
        return val;
    }
    
    /** Get the front element. */
    int peek() {
        shiftHelper();
        return olds.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return size() == 0;
    }
};
