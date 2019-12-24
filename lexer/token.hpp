#pragma once
#ifndef __TOKEN_HPP__
#define __TOKEN_HPP__

#include<iostream>

namespace si{

    enum TokenType{
        ILLEGAl = -1,
        ENDOFFILE,
        OP_PLUS,
        OP_MINUS,
        OP_MUL,
        OP_DIV,
        OP_MOD,
        LPAREN,
        RPAREN,
        INTEGER,
        DOUBLE,
        STRING,
    };
    

    class Token
    {
    private:
        TokenType type;
        std::string value;
    public:
        std::string ToString();
        std::string GetValue();
        int GetIntValue();
        double GetDblValue();
        TokenType GetType();
        Token(TokenType type,std::string val);
        ~Token();
    };
    
    
}

#endif