#include <iostream>

using namespace std;

class Rectangle{
    private:
    int length;
    int breadth;
    
    public:
    Rectangle(int length, int breadth){
        // this => member of class 
        this->length = length;
        this->breadth = breadth;
    }
    
    int area(){
        return length * breadth;
    }
};

int main(){
    Rectangle r(10, 20);
    cout << r.area();
}