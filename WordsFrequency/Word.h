//
//  Word.h
//  WordsFrequency
//
//

#ifndef WordsFrequency_Word_h
#define WordsFrequency_Word_h

#include <iostream>
using namespace std;

class Word {
public:
    Word();
    ~Word();
    void setWord(std::string s);
    std::string getWord();
    void setNum();
    uint16_t getNum();
private:
    std::string word;
    uint16_t num;
};

#endif
