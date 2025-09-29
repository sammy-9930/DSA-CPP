#include <iostream>

using namespace std;

class Parent{
    public:
    void display(){
        cout << "Display of parent" <<endl;
    }
};

class Child : public Parent{
    // public:
    // void display(){
        
    // }
};
int main(){
    Parent P;
    P.display();
    Child c;
    c.display();
    /* Both functions display method in parent class */
}

// OVERRIDING

#include <iostream>

using namespace std;

class Parent{
    public:
    void display(){
        cout << "Display of parent" <<endl;
    }
};

class Child : public Parent{
    public:
    void display(){
        cout << "Display of child " << endl;
    }
};
int main(){
    Parent P;
    P.display();
    Child c;
    c.display();
    /* redefining a function of parent in child class */
    /* can be used basic cars and automatic cars */
}