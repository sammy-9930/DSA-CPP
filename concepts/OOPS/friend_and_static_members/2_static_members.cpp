#include <iostream>

using namespace std; 

class Test{
    private:
    int a;
    int b;
    
    public:
    static int count; // static data member declaration
    
    Test(){   // constructor 
        a = 10;
        b = 10;
        count ++;
    }
};

int Test::count; 

int main(){
    Test t1;
    Test t2;
    // one copy of count used by both objects
    cout << Test::count;  // using class name
    cout << t1.count; // using object name
    cout << t2.count; // using object name
}

/*####################################################################################*/

// static member functions 
// can access only static data members of a class 

#include <iostream>

using namespace std; 

class Test{
    private:
    int a;
    int b;
    
    public:
    static int count;
    
    Test(){   // constructor 
        a = 10;
        b = 10;
        count ++;
    }
    
    static int getCount(){
        return count;
    }
};

int Test::count;

int main(){
    Test t1;
    Test t2;
    // one copy of count used by both objects
    cout << Test::count << endl;
    cout << t1.count << endl;
    cout << t2.count << endl;
    
    cout << Test::getCount()  << endl;
    cout << t1.getCount() << endl;
    cout << t2.getCount() << endl;
}