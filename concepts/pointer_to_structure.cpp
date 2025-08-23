#include <iostream>

using namespace std;

// creating rectangle object in stack
struct Rectangle{
    int length;
    int breadth;
};

int main(){
    Rectangle r = {10, 15};
    cout << r.length << endl;
    cout << r.breadth << endl;
    
    Rectangle *p = &r;
    cout << "using pointer" << endl;
    cout << p->length << endl;
    cout << p->breadth << endl;
}


// creating rectangle object in heap 
#include <iostream>

using namespace std;

struct Rectangle{
    int length;
    int breadth;
};

int main(){
    Rectangle *p;
    p = new Rectangle;
    p->length = 15;
    p->breadth = 7;
    cout << p->length << endl;
    cout << p->breadth << endl;
}