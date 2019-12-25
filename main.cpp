#include<iostream>
#include"./parser/node.hpp"
#include"./parser/parser.hpp"
int main(void){
    si::Parser * parser = new si::Parser("test.txt");
    si::Node * tree = parser->GetAST();
    std::cout<<"抽象语法树："<<tree->ToString()<<std::endl;
    std::cout<<"计算结果："<<tree->GetValue()<<std::endl;
    delete parser;
    return 0;
}