/*
When a function is specified as inline the whole code of the inline function is inserted or substituted at the 
point of its call during the compilation instead of using the normal function call mechanism.

if u define a function inside a class, automatically it is inline 
fun1 code is expanded within main function

outside the class => not inline 
*/

#include <iostream>

using namespace std;

class Test{
    public:
        void fun1(){
            cout << "InLine" << endl;
        }
        
        void fun2();
};

void Test::fun2(){
    cout << "Not InLine" << endl;
}

int main(){
    Test t;
    t.fun1();
    t.fun2();
}

/*#############################################################################################*/
// INLINE FUNCTION WITH ARGUMENTS 
// even though fun2 is defined outside the class, it is inline because of the inline keyword

#include <iostream>
using namespace std;
class Test{
    public:
        void fun1(int x){
            cout << "InLine " << x << endl;
        }
        
        inline void fun2(int x);
};
inline void Test::fun2(int x){
    cout << "InLine " << x << endl;
}
int main(){
    Test t;
    t.fun1(10);
    t.fun2(20);
}
