#include <iostream>

using namespace std;

class Base{
    public:
        void fun1(){
            cout << "fun1" << endl;
        }
        void fun2(){
            cout << "fun2" << endl;
        }
        void fun3(){
            cout << "fun3" << endl;
        }
};

class Derived: public Base{
    public:
        void fun4();
        void fun5();
};

int main(){
    Base *p = new Derived();
    /* calling base class functions */
    p->fun1();
    p->fun2();
    p->fun3();
    /*cannot call devired class methods*/
    /*
    saying a cuboid is a rectangle
    But a rectangle is not a cuboid
    cannot take a pointer of derived class and point it to base class object
     */
    
}