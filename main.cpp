#include<iostream>
#include"./filereader/filereader.hpp"
#include"./lexer/token.hpp"

int main(void){
    std::cout<<"Hello World!"<<std::endl;

    si::FileReader * rd = new si::FileReader("test.txt");
    std::cout<<rd->Read()<<std::endl;
    si::TokenValue val;
    val.iValue = 12;
    si::Token * token = new si::Token(si::INTEGER,&val);
    std::cout<<token->ToString()<<std::endl;
    delete rd;
    return 0;
}