#include <string>
#include <unordered_map>
using namespace std;

bool anagrams(std::string s1, std::string s2) {
    if (s1.length() != s2.length()){
        return false;
    } 
    unordered_map<char, int> countS;
    unordered_map<char, int> countT;
    
    for (int i=0; i < s1.length(); i++){
        countS[s1[i]]++;
        countT[s2[i]]++;
    }
    return countS == countT;
}


void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}