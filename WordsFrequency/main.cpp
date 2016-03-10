//
//  main.cpp
//  WordsFrequency
//
//

//数组头文件
#include <vector>
//字符串头文件
#include <string>
//创建的类的头文件
#include "Word.h"
//正则表达式头文件
#include <regex>

//文件操作头文件
#include <iostream>
#include <fstream>

//使用命名空间std
using namespace std;

std::vector<Word*> sortVector(std::vector<Word*> vec)
{
    //使用std::sort对vector进行排序，排序规则使用拉姆达表达式
    std::sort(vec.begin(), vec.end(), [](Word* w1, Word* w2){ return w1->getNum() > w2->getNum();});
    return vec;
}

void printAllObject(std::vector<Word*> vec)
{
    std::vector<Word*> newVec = sortVector(vec);        //得到排序后的新vector
    for (auto p : newVec) {
        if (p) {
            std::cout << p->getWord() << " : " << p->getNum() << endl;
        }
    }
}

void delectAllObject(std::vector<Word*> vec)
{
    for (int i = 0; i < vec.size(); ++i) {
        auto p = vec.at(i);
        if (p) {
            delete p;
        }
    }
}

int main(int argc, const char * argv[]) {
    const char* filename = "/Users/ericwang/Downloads/code/WordsFrequency/WordsFrequency/word.txt";        //绝对文件路径
    char* buffer;
    long size;
    ifstream file(filename, ios::in|ios::binary|ios::ate);      //打开文件
    size = file.tellg();        //获取文件长度
    file.seekg(0, ios::beg);
    buffer = new char[size];
    file.read(buffer, size);        //读取文件字符串到buffer里面
    file.close();
    
    std::vector<Word*> vec;         //容器用来存储所有word对象, 类似于数组, 但是可以存储对象类型
    
    
    const std::regex pattern("[a-zA-z]+");               //正则表达式匹配模式     \w是匹配字母 多加个\是转义 +号是匹配一个及以上的字母组合即单词
    std::string target = buffer;
    const std::sregex_token_iterator end;
    for (std::sregex_token_iterator i (target.begin(), target.end(), pattern); i != end; ++i) {             //遍历匹配字符串里所有符合匹配模式的单词
        std::string s = *i;                   //用s保存已经匹配到的字符串,即*i
        Word* p = new Word();       //先创建对象
        p->setWord(*i);                     //把匹配到的单词存储到对象里面
        p->setNum();                        //把改单词匹配次数+1
        bool isExist = false;             //用来标记是否该单词已经存储到数组vector里面
        for (auto p: vec) {                 //快速遍历vector 用来查看是否已经存在该单词 , auto 是自动获取vector里面存储的对象类型. p代表取出一个对象
            if (p && (p->getWord() == *i)) {            //如果取出的p不为空并且p的单词是当前匹配到的*i
                isExist = true;                                       //把isExist设置为true代表已经存在该单词
                p->setNum();                                       //把该单词的使用次数加1
                break;                                                    //已经找到该单词结束快速遍历
            }
        }
        if (!isExist) {                             //如果快速遍历结束, isExist的值还是false, 代表这是个新找到的单词, 需要存到vector里面
            vec.push_back(p);            //push到vector的最后一个位置
        }
    }
    
    printAllObject(vec);    //输出结果
    delectAllObject(vec);       //删除所有创建的对象
    delete buffer;          //删除缓冲字符串
    return 0;
}
