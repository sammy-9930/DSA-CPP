/* using two stacks
time: O(1)
space: O(n) */ 

class MinStack {
public:
    stack<int> stk;
    stack<int> min_stack;
    MinStack() {
        
    }
    
    void push(int val) {
        stk.push(val);
        if (!min_stack.empty()){
            val = min(val, min_stack.top());
        }
        min_stack.push(val);
    }
    
    void pop() {
        stk.pop();
        min_stack.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return min_stack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

/*
using one stack
time: O(n) for getMin
space: O(n)
*/
class MinStack {
public:
    stack<int> stk;
    MinStack() {

    }

    void push(int val) {
        stk.push(val);
    }

    void pop() {
        stk.pop();
    }

    int top() {
        return stk.top();
    }

    int getMin() {
        stack<int> tmp;
        int mini = stk.top();
        while (stk.size()) {
            mini = min(mini, stk.top());
            tmp.push(stk.top());
            stk.pop();
        }

        while (tmp.size()) {
            stk.push(tmp.top());
            tmp.pop();
        }

        return mini;
    }
};