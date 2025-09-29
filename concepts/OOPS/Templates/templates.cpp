// TEMPLATE FUNCTION 
#include <iostream>

using namespace std;

template <class T>
T maximum(T x, T y){
    return x>y ? x : y;
}

int main(){
    cout << maximum(10, 15) << endl;
    cout << maximum(50.5, 65.0) << endl;
    cout << maximum('a', 'z') << endl;
}

/*#########################################################################*/

// multiple parameters in templates
#include <iostream>

using namespace std;

template <class T, class R>
void add(T x, R y){
    cout << x + y;
}

int main(){
    add(10, 15.5);
}

/*#############################################################################*/
// TEMPLATE CLASS
