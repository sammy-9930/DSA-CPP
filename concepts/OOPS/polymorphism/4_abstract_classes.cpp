// If a class has pure virtual function, that class is called abstract class 
// Base b; => not possible 
// Base *p; => possible 

/*
Base class => all concrete methods => reusability 
Base class => some concrete and some pure virtual methods => reusability and polymorphism [ABSTRACT CLASS]
Base class => all pure virtual functions => polymorphism [INTERFACE] [ABSTRACT CLASS]
*/

#include <iostream>

using namespace std;

class Base{
    public:
    void fun1(){
        cout << "Base fun1" << endl;
    }
    // pure virtual function
    virtual void fun2() = 0;
};

class Derived : public Base{
    public:
    void fun2(){
        cout << "Derived fun2" << endl;
    }
};

int main(){
    
}