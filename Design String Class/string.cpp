#include <iostream>
#include <cstring>

using namespace std;

class String{
    private:
        int size;
        char* c;
    public:
        // default constructor
        String() : c(nullptr), size(0){

        }

        // parameterized constructor
        String(const char* s1){
            int n = strlen(s1);
            c = new char[n+1];
            strncpy(c, s1, n+1);
            size = n;
        }

        // copy constructor
        String(const String &s2){
            size = s2.size;
            c = new char[size+1];
            strncpy(c, s2.c, size);
            c[size] = '\0';
        }
        
        // copy assignment operator 
        String& operator=(String& str3){
            // handle cases like str1 = str1 
            if(this != &str3){
                // delete whatever is first assigned to avoid memory leak 
                delete[] c;
                size = str3.size;
                c = new char[size+1];
                strncpy(c, str3.c, size);
                c[size] = '\0';
            }
            return *this;
        }
        
        int getLength(){
            return size;
        }

        friend ostream& operator<<(ostream& out, const String& str);
        friend istream& operator>>(istream& in, String& str);

        ~String(){
            delete[] c;
        }
};

ostream& operator<<(ostream& out, const String& str){
    out<<str.c;
    return out;
}

istream& operator>>(istream& in, String& str){
    in>>str.c;
    return in;
}

int main(){
    // default constructor 
    String str1; 
    // parameterized constructor 
    String str2 = "hello";
    // copy constructor 
    String str3 = str2;
    // assignment operator 
    str1 = str3;
}
