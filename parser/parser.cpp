#include<iostream>
#include"../lexer/token.hpp"
#include"../lexer/lexer.hpp"
#include"node.hpp"
#include"parser.hpp"

namespace si{

    Node * Parser::GetAST(){
        ast = GetExpr();
        return ast;
    };

    Node * Parser::GetExpr(){
        // Term[+/- Term]*
        Node * left = GetTerm();
        while(type == OP_PLUS || type == OP_MINUS){
            Node * op = new Node(token);
            op->SetLeft(left);
            op->SetRight(GetTerm());
            left = op;
            op = nullptr;
        }
        
        return left;
    }

    Node * Parser::GetTerm(){
        // Fact[+/- Fact]*
        Node * left = GetFact();
        while(type == OP_MUL || type == OP_DIV){            
            Node * op = new Node(token);
            op->SetLeft(left);
            op->SetRight(GetFact());
            left = op;
            op = nullptr;
        }

        return left;
    }

    Node * Parser::GetFact(){
        token = lexer ->GetToken();
        type = token->GetType();
        
        if (type == ENDOFFILE)
        {
            return nullptr;
        }
        if((type & VALUE) >0){
            Token * temp =  token ;
            token = lexer ->GetToken();   
            type = token->GetType();         
            return new Node(temp);
        }    

        Node * expr = nullptr;
        if(type == LPAREN){
            expr = GetExpr();           
            if (type != RPAREN)
            {
                delete expr;
                expr = nullptr;
                throw std::invalid_argument("缺少右括号");
            }  
            // 读取完右括号要紧接着读取下一个token          
            token = lexer ->GetToken();   
            type = token->GetType();  
            return expr;
        } 
        
        throw std::invalid_argument("不能识别的语法");
        return nullptr;
    }

    



    
    Parser::Parser(Lexer * _lexer){
        std::cout<<"创建parser"<<std::endl;
        lexer = _lexer;
    }

    Parser::Parser(const char * file){
        std::cout<<"创建parser"<<std::endl;
        lexer = new Lexer(file);
    }

    Parser::~Parser(){
        delete ast;
        ast = nullptr;
        delete lexer;
        lexer = nullptr;
        std::cout<<"销毁parser"<<std::endl;
    }
}
