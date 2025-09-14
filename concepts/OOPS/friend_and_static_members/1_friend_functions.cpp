/*
FRIEND FUNCTIONS 
Friend functions can access all the members of a class upon object. 
*/

#include <iostream>

using namespace std; 

class Test{
    private:
        int a;
    protected:
        int b;
    public:
        int c; 
    // declaraction
    friend void fun();
};

void fun(){
    Test t;
    t.a = 15; 
    t.b = 10;
    t.c = 5;
    cout << t.a << t.b << t.c; // 15 10 5
}

int main(){
    fun();
}

/*######################################################################################*/

/*
FRIEND CLASS
They can access members of object of other classes 
*/


#include <iostream>

using namespace std; 

class Your; // declaration - otherwise error

class My{
    private:
    int a = 10;
    friend Your; // friend class
};

class Your{ //definition
    public:
    My m;
    void fun(){
        cout << m.a << endl; //10
    }
};

int main(){
    Your Y;
    Y.fun();
}

