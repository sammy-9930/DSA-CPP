/*
using two stacks - brute force 
time complexity: O(1)=> initialization, O(1) => push, O(n) => push, O(n) =>peek, O(1) => empty
space complexity: O(n)
*/
class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        while (!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }

        int top = s2.top();
        s2.pop();

        while (!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }

        return top;
        
    }
    
    int peek() {
        while (!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }

        int top = s2.top();

        while (!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        return top;
    }
    
    bool empty() {
        return s1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

/*
using two stacks: amortized complexity
time complexity: o(1) => push, O(1) => empty 
if we have multiple pushes and then average time pop => O(1) and peek => O(1)
space complexity: O(n)
*/
class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        int top;
        if (!s2.empty())
        {
            top = s2.top();
            s2.pop();
        }
        else
        {
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
            top = s2.top();
            s2.pop();
        }
        return top;
    }
    
    int peek() {
        int top;
        if (!s2.empty()){
            top = s2.top();
        }
        else{
            while (!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            top = s2.top();
        }
        return top;   
    }
    
    bool empty() {
        return (s1.empty() && s2.empty());
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
