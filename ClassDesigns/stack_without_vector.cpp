#include <iostream>

using namespace std;

template <class T>
class Stack{
    private:
    T* data;
    int capacity;
    int count;
    
    public:
    Stack() {
        count = 0;
        capacity = 4;
        data = new T[capacity];
    }
    
    Stack(const Stack<T> &s){
        capacity = s.capacity;
        count = s.count;
        data = new T[capacity];
        for (int i = 0; i < count; i++) {
            data[i] = s.data[i];
        }
    }
    
    Stack& operator=(const Stack& s) {
        if (this != &s) {
            T* tmp = new T[s.capacity];
    
            for (int i = 0; i < s.count; i++) {
                tmp[i] = s.data[i];
            }
    
            delete[] data;
    
            data = tmp;
            capacity = s.capacity;
            count = s.count;
        }
        return *this;
    }
    
    Stack(Stack&& s) noexcept {
        data = s.data;
        capacity = s.capacity;
        count = s.count;
    
        s.data = nullptr;
        s.capacity = 0;
        s.count = 0;
    }
    
    Stack& operator=(Stack&& s) noexcept {
        if (this != &s) {
            delete[] data;
    
            data = s.data;
            capacity = s.capacity;
            count = s.count;
    
            s.data = nullptr;
            s.capacity = 0;
            s.count = 0;
        }
        return *this;
    }
    
    int size(){
        return count;
    }
    
    bool isEmpty(){
        return count == 0;
    }
    
    void push(T val){
        if(count == capacity){
            capacity *= 2;
            T* tmp = new T[capacity];
            for(int i = 0; i < count; i++){
                tmp[i] = data[i];
            }
            delete[] data;
            data = tmp;
        }
        data[count] = val;
        count++;
    }
    
    void pop(){
        if(isEmpty())
            throw underflow_error("Stack is empty");
        data[count - 1] = T{};
        count--;
    }
    
    T& top(){
        if(isEmpty())
            throw underflow_error("Stack is empty");
        return data[count-1];
    }
    
    ~Stack(){
        delete[] data;
    }
};
