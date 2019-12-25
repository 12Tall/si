#include<iostream>
#include"./lexer/token.hpp"
#include"./lexer/lexer.hpp"
#include"./parser/node.hpp"

int main(void){
    std::cout<<"Hello World!"<<std::endl;

    si::Node * left = new si::Node(new si::Token(si::INTEGER,"97"));
    si::Node * right = new si::Node(new si::Token(si::INTEGER,"9.7"));
    si::Node * op = new si::Node(new si::Token(si::OP_DIV,"/"));
    op->SetLeft(left);
    op->SetRight(right);
    std::cout<<op->GetValue()<<std::endl;

    delete op;
    // si::Lexer * lexer = new si::Lexer("test.txt");
    


    // si::Token * token;
    // do{
    //     token = lexer->GetToken();
    //     std::cout<<token->ToString()<<std::endl;
    // }    while (token->GetType() != si::ENDOFFILE  );
    
    // delete lexer;

    return 0;
}