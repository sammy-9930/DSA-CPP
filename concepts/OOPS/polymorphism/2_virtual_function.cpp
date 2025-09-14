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
    Parent *p = new Child();
    p->display();
    /*
    Base class function is used 
    function is called based on pointer
    */
}


#include <iostream>

using namespace std;

class Parent{
    public:
    virtual void display(){
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
    Parent *p = new Child();
    p->display();
    /*
    By using virtual keyword, function of child class can be called
    */
}