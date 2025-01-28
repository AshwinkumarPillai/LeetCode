// Single Queue | PUSH - O(N) | POP - O(1) | 0ms - Best soln (with queues)
class MyStack {
public:
    
    queue<int>q;
    
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        int sz = q.size();
        while(sz > 1){
            q.push(q.front());
            q.pop();
            sz--;
        }
    }
    
    int pop() {
        int x = q.front();q.pop();
        return x;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.size() == 0;
    }
};


// TWO Queue | PUSH - O(1) | POP - O(N) | 0ms
class MyStack {
public:
    
    int topElem;
    queue<int>q;
    queue<int>q2;
    
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        topElem = x;
    }
    
    int pop() {
        while(q.size() > 1){
            topElem = q.front();
            q.pop();
            q2.push(topElem);
        }
        int x = q.front();q.pop();
        swap(q, q2);
        return x;
    }
    
    int top() {
        return topElem;
    }
    
    bool empty() {
        return q.size() == 0;
    }
};

// TWO Queue | PUSH - O(N) | POP - O(1) | 0ms
class MyStack {
public:
    
    int topElem;
    queue<int>q;
    queue<int>q2;
    
    MyStack() {
        
    }
    
    void push(int x) {
        q2.push(x);
        topElem = x;
        
        while(q.size() > 0){
            q2.push(q.front());
            q.pop();
        }
        swap(q,q2);
    }
    
    int pop() {
        int x = q.front();q.pop();
        if(q.size() > 0) topElem = q.front();
        return x;
    }
    
    int top() {
        return topElem;
    }
    
    bool empty() {
        return q.size() == 0;
    }
};

// With Array - PUSH, POP - O(1) | 0ms
class MyStack {
public:
    
    int i = -1;
    int arr[200];
    
    MyStack() {
        
    }
    
    void push(int x) {
        i++;
        arr[i] = x;
    }
    
    int pop() {
        i--;
        return arr[i+1];
    }
    
    int top() {
        return arr[i];
    }
    
    bool empty() {
        return i == -1;
    }
};