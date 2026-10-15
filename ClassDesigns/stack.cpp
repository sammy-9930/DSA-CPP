/*
Requirements 
last in first out datastructure 
i/p : integers 
methods: empty, push, pop, top
*/
#include <iostream>
#include <vector>

using namespace std;

class Stack{
    private:
        vector<int> stk;
        
    public:
        Stack(){
            
        }
        
        bool isEmpty(){
            return (stk.size() == 0) ? true : false;
        }
        
        void push(int val){
            stk.push_back(val);
        }
        
        void pop(){
            if (isEmpty()){
                cout << "Stack is empty. Nothing to pop \n";
            }
            stk.pop_back();
        }
        
        int top(){
            if (isEmpty())
                cout << "Stack is empty.\n";
            int n = stk.size();
            return stk[n-1];
        }
};

int main(){
    Stack s1;
    s1.push(3);
    s1.push(2);
    s1.push(1);
    cout << s1.top() << endl;
}
