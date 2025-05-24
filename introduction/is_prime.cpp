#include <iostream>
#include <cmath>

bool isPrime(int n){
    if (n < 2){
        return false;
    }
    for(int i = 0; i <= sqrt(n); i++){
        if (n % i == 0){
            return false;
        }
    }
    return true; 
}

int main(){
    bool result = isPrime(7);
    std::cout << result;
    return 0; 
}
