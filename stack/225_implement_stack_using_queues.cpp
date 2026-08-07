/*
Using two queues 
time complexity: O(n) => push, O(1) => initialization, O(1) => pop
space complexity: O(n)
*/
class MyStack {
public:
    queue<int> q1;
    queue<int> q2;

    MyStack() {
        
    }
    
    void push(int x) {
        q2.push(x);
        while (!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        } 
        swap(q1, q2);
    }
    
    int pop() {
        int top = q1.front();
        q1.pop();
        return top;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

/*
Using single queues 
time complexity: O(n) => push, O(1) => initialization, O(1) => pop
space complexity: O(n)
*/
class MyStack {
public:
    queue<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
        for(int i = q.size() - 1; i > 0; i--){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int top = q.front();
        q.pop();
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

