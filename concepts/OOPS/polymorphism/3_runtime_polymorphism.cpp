// GENERALIZATION
/* same statement, function calls are different because of different objects*/
#include <iostream>

using namespace std;

class Car{
    public:
    virtual void start(){
        cout << "Car started" <<endl;
    }
    virtual void stop(){
        cout << "Car stopped" <<endl;
    }
};

class Innova : public Car{
    public:
    void start(){
        cout << "Innova started" <<endl;
    }
    void stop(){
        cout << "Innova stopped" <<endl;
    }
};

class Swift : public Car{
    public:
    void start(){
        cout << "Swift started" <<endl;
    }
    void stop(){
        cout << "Swift stopped" <<endl;
    }
};

int main(){
    Car *c = new Innova();
    c->start();  //Innova started
    c = new Swift();
    c->start(); // Swift started 
}

/*#############################################################################################*/

// PURE VIRTUAL FUNCTION
/* Force the derived class to implement the base class methods */

// Class car becomes abstract class. Cannot create object of abstract class
class Car{
    public:
    virtual void start() = 0; // pure virtual function 
    virtual void stop() = 0;  // pure virtual function
};

class Innova : public Car{
    public:
    void start(){
        cout << "Innova started" <<endl;
    }
    void stop(){
        cout << "Innova stopped" <<endl;
    }
};

class Swift : public Car{
    public:
    void start(){
        cout << "Swift started" <<endl;
    }
    void stop(){
        cout << "Swift stopped" <<endl;
    }
};

int main(){
    Car *c = new Innova();
    c->start();  
    c = new Swift();
    c->start(); 
}
