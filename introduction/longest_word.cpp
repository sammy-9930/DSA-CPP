#include <iostream>
#include <sstream>

std::string longestWord(std::string sentence){
    std::stringstream ss(sentence);
    std::string long_word;
    std::string word;
    while (std::getline(ss, word, ' ')){
        if (word.size() >= long_word.size()){
            long_word = word;
        }
    }
    return long_word; 
}

void run(){
    std::string result = longestWord("what a wonderful world");
    std::cout << result; 
}