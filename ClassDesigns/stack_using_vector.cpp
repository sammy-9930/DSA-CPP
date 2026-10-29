#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <typename T>
class Stack{
    private:
        vector<T> data;
    public:
        void push(T val){
            data.push_back(val);
        }
        
        void pop(){
            if(isEmpty())
                throw underflow_error("Stack is empty");
            data.pop_back();
        }
        
        T& top(){
            if(isEmpty())
                throw runtime_error("No elements found in stack");
            return data[data.size()-1];
        }
        
        bool isEmpty(){
            return data.empty();
        }
        
        int size(){
            return data.size();
        }
        
        void display(){
            cout << "Elements in stack : " << endl;
            for(auto element : data){
                cout << element << endl;
            }
        }
};

int main(){
    Stack<int> s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.display();
    cout << "Top element of stack: " << s1.top();
    s1.pop();
    s1.pop();
    s1.pop();
    s1.isEmpty();
}
