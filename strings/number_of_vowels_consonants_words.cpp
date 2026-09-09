// Online C++ compiler to run C++ program online
/*
Enter a string: 
how Many wOrds54
Number of vowels : 3
Number of Consonants: 9
Number of Words: 3
*/
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;


int main() {
    // Write C++ code here
    string str;
    cout << "Enter a string: " << endl;
    getline(cin, str);
    unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    int n_vowels = 0;
    int consonants = 0;
    int words = 0;
    for(int i = 0; str[i] != '\0'; i++){
        // count words 
        if (i > 0 && (str[i] != ' ' && str[i-1] == ' ')){
            words++;
        }

        // count vowels and consonants 
        if (vowels.count(str[i]) != 0){
            n_vowels++;
        }
        else if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')){
            consonants++;
        }
    }
    cout << "Number of vowels : " << n_vowels << endl;
    cout << "Number of Consonants: " << consonants << endl;
    cout << "Number of Words: " << words+1 << endl;

    return 0;
}
