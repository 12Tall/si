#pragma once
#ifndef __TOKEN_HPP__
#define __TOKEN_HPP__

#include<iostream>

namespace si{

    enum TokenType{
        // 数值类型
        VALUE = 0x00000100,
        INTEGER,
        DOUBLE,
        STRING,
        // 运算符类型
        OP = 0x00002000,
        OP_PLUS,
        OP_MINUS,
        OP_MUL,
        OP_DIV,
        OP_MOD,
        // 界符
        DELIMITER=0x00004000,
        LPAREN,
        RPAREN,
        // 控制字符
        CONTROL = 0x80000000,
        ENDOFFILE ,
        ILLEGAl,
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