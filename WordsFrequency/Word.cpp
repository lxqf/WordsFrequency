//
//  Word.cpp
//  
//
//
//

#include <stdio.h>
#include "Word.h"

Word::Word():
word("")
,num(0)
{
}
Word::~Word()
{
    
}
void Word::setWord(std::string s)
{
    word = s;
}
std::string Word::getWord()
{
    return word;
}
void Word::setNum()
{
    ++num;
}
uint16_t Word::getNum()
{
    return num;
}

