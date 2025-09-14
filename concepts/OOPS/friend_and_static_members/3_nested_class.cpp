// Inner class can access members of outer class if they are static 
// The outer class can access all the members of a inner class [only public members]

#include <iostream>

using namespace std;

class Outer{
    public:
    int a = 10;
    static int b;
    void fun(){
        i.show();
        cout << i.x << endl;
        
    }
    class Inner{
        public:
        int x = 25;
        void show(){
            cout << "Show";
        }
        
    };
    Inner i; // create object 
};

