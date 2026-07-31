/*
Brute force solution - TLE
Time complexity : O(n) for getMin() and O(1) for other operations
Space complexity: O(n) for getMin() and O(1) for other operations
*/
class MinStack {
public:
    stack<int> stk;
    MinStack() {
        
    }
    
    void push(int value) {
        stk.push(value);
    }
    
    void pop() {
        stk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        stack<int> tmp;
        int smallest = stk.top();
        while (!stk.empty()){
            smallest = min(smallest, stk.top());
            tmp.push(stk.top());
            stk.pop(); 
        }
        while (!tmp.empty()){
            stk.push(tmp.top());
            tmp.pop();
        }
        return smallest;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */


/*
Optimization - Two stacks 
Time complexity: O(1) for all operations 
Space complexity: O(n)
*/
class MinStack {
public:
    stack<int> stk1;
    stack<int> stk2;
    MinStack() {
        
    }
    
    void push(int value) {
        stk1.push(value);
        if (!stk2.empty() && (value >= stk2.top()))
            stk2.push(stk2.top());
        else
            stk2.push(value);
        
    }
    
    void pop() {
        stk1.pop();
        stk2.pop();
    }
    
    int top() {
        return stk1.top();
    }
    
    int getMin() {
        return stk2.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
