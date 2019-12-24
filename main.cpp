#include<iostream>
#include"./filereader/filereader.hpp"
#include"./lexer/token.hpp"
#include"./lexer/lexer.hpp"

int main(void){
    std::cout<<"Hello World!"<<std::endl;

    si::Lexer * lexer = new si::Lexer("test.txt");
    
    std::cout<<lexer->GetToken()->ToString()<<std::endl;
    
    std::cout<<lexer->GetToken()->ToString()<<std::endl;
    // std::cout<<lexer->GetToken()->ToString()<<std::endl;
    // std::cout<<lexer->GetToken()->ToString()<<std::endl;
    delete lexer;

    // si::FileReader * rd = new si::FileReader("test.txt");
    // std::cout<<rd->Read()<<std::endl;
    // si::TokenValue val;
    // si::Token * token = new si::Token(si::INTEGER,"97");
    // std::cout<<token->ToString()<<std::endl;
    // delete token;
    // delete rd;
    return 0;
}