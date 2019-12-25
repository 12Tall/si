#pragma once
#ifndef __PARSER_HPP__
#define __PARSER_HPP__

#include<iostream>
#include"../lexer/token.hpp"
#include"../lexer/lexer.hpp"
#include"node.hpp"

namespace si{
    class Parser
    {
        private:
            Token * token;
            TokenType type;

            Lexer * lexer;

            Node * ast;
            
            // 获取因数
            Node * GetFact();
            // 获取加数
            Node * GetTerm();
            // 获取表达式
            Node * GetExpr();
        public:
            Node * GetAST();
            Parser(Lexer * _lexer);
            Parser(const char  * file);
            ~Parser();
        };
    

    
}

#endif